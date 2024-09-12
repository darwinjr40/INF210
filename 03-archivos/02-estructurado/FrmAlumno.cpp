//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmAlumno.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//para ver la posicion
//		std::streampos fileSize = pf->tellg();
//		ShowMessage(AnsiString(static_cast<long long>(fileSize)));
//		fileSize = pf->tellp();
//		ShowMessage(AnsiString(static_cast<long long>(fileSize)));
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	nomArch="Alumno.dat";
	nomArchIdxCod = "codigo.idx";
	nomArchIdxFecha = "fecha.idx";
	pf = new fstream(nomArch.c_str(),ios::in|ios::binary);
	if (pf->fail()){
	  delete pf;
	  pf = new fstream(nomArch.c_str(),ios::out|ios::binary);
	}
	pf->close();
	delete pf;
}
//---------------------------------------------------------------------------

void TForm1::UpdateForm(AnsiString cod="",AnsiString nom="",AnsiString dir="", AnsiString fecha=""){
  Edit1->Text = cod;
  Edit2->Text = nom;
  Edit3->Text = dir;
  MaskEdit1->Text = fecha;
}

void TForm1::ShowAlumno(RegAlumno r){
  Edit1->Text = r.cod;
  Edit2->Text = r.nom;
  Edit3->Text = r.dir;
  MaskEdit1->Text = r.fecha.ToString();
}

Cardinal StrtoInt(AnsiString cad) {
	Cardinal nu = 0;
	for (byte i = 1; i <= cad.Length(); i++) {
		if ((cad[i] >= '0') && (cad[i] <= '9'))
			nu = nu * 10 + cad[i] - 48;
	}
	return nu;
}

void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
	RegAlumno reg;
	Word cod = StrtoInt(Edit1->Text);
	pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
	if ( !pf->fail() ) {
		pf->read((char*)&reg, sizeof(reg));
		while( !pf->eof() && (reg.cod != cod || reg.marca != 0) ) {
//		  ShowMessage(reg.ToString());
		  //hallado = (rg.cod == cod && rg.marca == 0), aplico not
		  //(rg.cod != cod || rg.marca != 0), aplico not
		  pf->read((char*)&reg, sizeof(reg));
		};
		if (pf->eof()) //es fin de archivo
		  UpdateForm(IntToStr(cod));
		else
		  ShowAlumno(reg);
	}
	pf->close();
	delete pf;
}
//---------------------------------------------------------------------------
void TForm1::SaveAlumno(RegAlumno regNuevo){
	RegAlumno reg;
	if (pf->is_open()) {
		pf->read((char*)&reg, sizeof(reg));
		while( !pf->eof() && (reg.cod != regNuevo.cod || reg.marca != 0) ) {
		  pf->read((char*)&reg, sizeof(reg));
		};
		if ( pf->eof() )
		  pf->seekg(0,ios::end); //add
		else
		  pf->seekg(-sizeof(reg), ios::cur); //update
		pf->write((char *)&regNuevo, sizeof(regNuevo));
		UpdateForm();
	}
}

void __fastcall TForm1::GuardarClick(TObject *Sender)
{
	RegAlumno regNuevo;
	regNuevo.cod = StrtoInt(Edit1->Text);
	strcpy(regNuevo.nom, (AnsiString(Edit2->Text)).c_str());
	strcpy(regNuevo.dir,(AnsiString(Edit3->Text)).c_str());
	regNuevo.fecha = TFecha(StrtoInt(MaskEdit1->Text.SubString(1, 2)), StrtoInt(MaskEdit1->Text.SubString(4, 2)), StrtoInt(MaskEdit1->Text.SubString(7, 4)));

	pf = new fstream(nomArch.c_str(), ios::in | ios::out | ios::binary);
	this->SaveAlumno(regNuevo);
	pf->close();
	delete pf;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actualizarClick(TObject *Sender)
{
	RegAlumno reg;
	Cardinal p = 0;
	pf = new fstream(nomArch.c_str(), ios::in | ios::out | ios::binary);
	if ( !pf->fail() ) {
		pf->read((char*)&reg, sizeof(reg));
		while( !pf->eof() ) {
			for (byte i = 0; i < strlen(reg.nom); i++)
			  reg.nom[i] = toupper(reg.nom[i]);
			pf->seekp(-sizeof(reg),ios::cur);
			pf->write((char *)&reg, sizeof(reg));
			p++;
			pf->seekp(p*sizeof(reg));
			pf->seekg(p*sizeof(reg));
			pf->read((char*)&reg, sizeof(reg));
		}
	}
	pf->flush();
	pf->close();
	delete pf;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::actualizarv3(TObject *Sender)
{
	RegAlumno reg;
	fstream f(nomArch.c_str(), ios::in | ios::out | ios::binary);
	if ( !f.fail() ) {
		f.read((char*)&reg, sizeof(reg));
		while( !f.eof() ) {
			for (byte i = 0; i < strlen(reg.nom); i++)
			  reg.nom[i] = toupper(reg.nom[i]);
			f.seekp(-sizeof(reg),ios::cur);
			f.write((char *)&reg, sizeof(reg));
			f.seekg(f.tellg());
			f.read((char*)&reg, sizeof(reg));
		}
	}
	f.flush();
	f.close();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::actualizarv4Click(TObject *Sender)
{
	RegAlumno reg;
	fstream f(nomArch.c_str(), ios::in | ios::out | ios::binary);
	if ( !f.fail() ) {
		while(f.read((char*)&reg, sizeof(reg))) {
		  for (byte i = 0; i < strlen(reg.nom); i++)
			reg.nom[i] = toupper(reg.nom[i]);
		  f.seekp(-sizeof(reg),ios::cur);
		  f.write((char *)&reg, sizeof(reg));
		  f.seekg(f.tellg());
		}
	}
	f.flush();
	f.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender){
	RegAlumno reg;
	fstream f(nomArch.c_str(), ios::in | ios::out | ios::binary);
	if ( !f.fail() ) {
		// Lee dos registros, pero no se utiliza el resultado
//		(f.read((char*)&reg, sizeof(reg)));
//		(f.read((char*)&reg, sizeof(reg)));

		// Aquí estaba el error: se debe crear el nuevo registro antes de realizar la escritura
//		reg = RegAlumno(300, "Juan Perez", "calle 123", TFecha(10,10,1010));
//		ShowMessage(IntToStr(f.tellg()));
		f.write((char*)&reg, sizeof(reg));

//		f.seekp(-sizeof(reg),ios::cur);
//		ShowMessage(IntToStr(f.tellg()));
//		ShowMessage(IntToStr(f.tellp()));
//		f.write((char*)&reg, sizeof(reg));
//		ShowMessage(IntToStr(f.tellg()));
//		ShowMessage(IntToStr(f.tellp()));
////		f.seekg(0,ios::cur);
//		f.seekg(f.tellg());
//		(f.read((char*)&reg, sizeof(reg)));
//		(f.read((char*)&reg, sizeof(reg)));
//
//		reg = RegAlumno(200, "Juan Perez", "calle 123", TFecha(10,10,1010));
//		f.seekp(-sizeof(reg),ios::cur);
//		f.write((char*)&reg, sizeof(reg));
//
//		f.seekg(f.tellg());
//		(f.read((char*)&reg, sizeof(reg)));
	}
	f.flush();
	f.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actualizarv2Click(TObject *Sender)
{
	RegAlumno reg;
	AnsiString nameTmp = "temporal.tmp";
	fstream *ft = new fstream(nameTmp.c_str(), ios::out | ios::binary);
	pf = new fstream(nomArch.c_str(), ios::in | ios::out | ios::binary);
	if ( !pf->fail() ) {
		pf->read((char*)&reg, sizeof(reg));
		while( !pf->eof() ) {
		  for (byte i = 0; i < strlen(reg.nom); i++)
			reg.nom[i] = toupper(reg.nom[i]);
		  ft->write((char *)&reg, sizeof(reg));
		  pf->read((char*)&reg, sizeof(reg));
		};
	}
	pf->flush();
	pf->close();
	delete pf;
	ft->flush();
	ft->close();
	delete ft;
	remove(nomArch.c_str());
	rename(nameTmp.c_str(),nomArch.c_str());
}


//---------------------------------------------------------------------------
void __fastcall TForm1::expandirClick(TObject *Sender) {
  RegAlumno reg;
  RegAlumnoNew regANew;
  fstream ph(nomArch.c_str(),ios::in|ios::out|ios::binary);
  fstream pj( AnsiString("AlumnosNew.dat").c_str(),ios::out|ios::trunc|ios::binary);
  if (!ph.fail()) {
	  while (ph.read((char*)&reg,sizeof(reg))){
		 regANew  = RegAlumnoNew(reg.cod, reg.nom, reg.dir, reg.fecha);
		 pj.write((char*)&regANew,sizeof(regANew));
	  }
  }
  ph.flush();
  ph.close();
  pj.flush();
  pj.close();
}




//---------------------------------------------------------------------------

void __fastcall TForm1::showExpandirClick(TObject *Sender)
{
	RegAlumnoNew reg;
	fstream f( AnsiString("AlumnosNew.dat").c_str(), ios::in | ios::binary);
	if ( !f.fail() ) {
		while(f.read((char*)&reg, sizeof(reg)))
		  ShowMessage(reg.cod);
	}
	f.close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11Click(TObject *Sender)
{
//   RegAlumno ra, rb;
//   ra.cod = 100;
//   ra.fecha.dia = 5;
////   rb = RegAlumno(ra);
//   rb = ra;
//   rb.cod = 200;
//   rb.fecha.dia = 10;
//   ShowMessage(ra.ToString());
//   ShowMessage(rb.ToString());

//	RegIdxCodV1* estrategiaA = new RegIdxCodV1();
//	RegIdxNom* estrategiaB = new RegIdxNom();
//
////	Registro* reg =  new Registro(estrategiaA, sizeof(*estrategiaA));
//	Registro reg= {estrategiaA, sizeof(*estrategiaA)};
//	ShowMessage(sizeof(*estrategiaA));
//	ShowMessage(sizeof(*estrategiaB));
//	ShowMessage(sizeof(reg));
//	ShowMessage(reg.size);

//   ShowMessage(this->regIdx->pos);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::mostrarClick(TObject *Sender)
{
	AnsiString datos[] = {"cod", "nombre", "direccion", "fecha", "marca", "telefono"};
	byte c = 0;
	int n = sizeof(datos) / sizeof(datos[0]);
	RegAlumno reg;
	fstream fi(nomArch.c_str(), ios::in | ios::binary);
	if ( !fi.fail() ) {
		fi.read((char*)&reg, sizeof(reg));
		while( !fi.eof()) {
		  c++;
		  StringGrid1->Cells[0][c] = reg.cod;
		  StringGrid1->Cells[1][c] = reg.nom;
		  StringGrid1->Cells[2][c] = reg.dir;
		  StringGrid1->Cells[3][c] = reg.fecha.ToString();
		  StringGrid1->Cells[4][c] = reg.marca;
		  StringGrid1->Cells[5][c] = reg.telefono;
		  fi.read((char*)&reg, sizeof(reg));
		};
	}
	fi.close();

	for (byte i = 0; i < n; i++) {
	   StringGrid1->Cells[i][0] = datos[i];
	}
//	delete[] datos;
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = c+1;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::expandirFileClick(TObject *Sender)
{
  RegAlumnoAnt regAnt;
  RegAlumno reg;
  fstream fa(nomArch.c_str(),ios::in|ios::out|ios::binary);
  fstream fb( AnsiString("temporal.tmp").c_str(),ios::out|ios::trunc|ios::binary);
  if ( !fa.fail() ) {
	  while ( fa.read((char*)&regAnt,sizeof(regAnt)) ){
		 reg  = RegAlumno(regAnt.cod, regAnt.nom, regAnt.dir, regAnt.fecha);
		 fb.write((char*)&reg,sizeof(reg));
	  }
  }
  fa.close();
  fb.close();
  remove(this->nomArch.c_str());
  rename("temporal.tmp", this->nomArch.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarClick(TObject *Sender)
{
  RegAlumno rg;
  Word cod = StrToInt(Edit1->Text);
  fstream f(nomArch.c_str(),ios::in|ios::out|ios::binary);
  if ( !f.fail() ) {
	  f.read((char*)&rg,sizeof(rg));
	  while ( !f.eof() && (rg.cod != cod || rg.marca != 0)){
		f.read((char*)&rg,sizeof(rg));
	  }
	  if ( !f.eof() ) {
		 rg.marca = 1;
		 f.seekg(-sizeof(rg), ios::cur);
		 f.write((char*)&rg, sizeof(rg));
		 UpdateForm();
	  }
  }
  f.close();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxIniClick(TObject *Sender){
	RegIdxCod regIdx;
	RegAlumno regA;
	pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
	pfi = new fstream(nomArchIdxCod.c_str(), ios::in | ios::binary);
	if ( pfi->is_open() ) {
		this->ButtonNavIdxIni->Enabled = false;
		pfi->read((char*)&regIdx, sizeof(regIdx));
		if ( !pfi->eof() ) {
			pf->seekg(regIdx.pos, ios::beg);
			pf->read((char *)&regA, sizeof(regA));
			this->ShowAlumno(regA);
			this->ButtonNavIdxSig->Enabled = true;
			this->ButtonNavIdxAnt->Enabled = true;
			this->ButtonNavIdxFin->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxSigClick(TObject *Sender){
	RegIdxCod regIdx;
	RegAlumno reg;
	if ( pfi->is_open() ) {
		ButtonNavIdxAnt->Enabled = true;
		pfi->read((char*)&regIdx, sizeof(regIdx));
		if ( pfi->eof() ) {
			pfi->close();
			delete pfi;
			pfi = new fstream(nomArchIdxCod.c_str(), ios::in | ios::binary);
			pfi->seekg(0, ios::end);
//			pfi->seekg(0);
			ButtonNavIdxSig->Enabled = false;
		} else {
			pf->seekg(regIdx.pos, ios::beg);
			pf->read((char *)&reg, sizeof(reg));
			this->ShowAlumno(reg);
			ButtonNavIdxSig->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxAntClick(TObject *Sender){
	RegIdxCod regIdx;
	RegAlumno reg;
	Cardinal p;
	if ( pfi->is_open() ) {
		p = pfi->tellg();
		if (p <= sizeof(regIdx)) { // si esta en el primer registro del idx
			ButtonNavIdxAnt->Enabled = false;
		} else {
			pfi->seekg(-2*sizeof(regIdx), ios::cur);
			pfi->read((char*)&regIdx, sizeof(regIdx));
			if ( !pfi->eof() ) {
				pf->seekg(regIdx.pos, ios::beg);
				pf->read((char *)&reg, sizeof(reg));
				this->ShowAlumno(reg);
				ButtonNavIdxAnt->Enabled = true;
				ButtonNavIdxSig->Enabled = true;
			}
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxFinClick(TObject *Sender)
{
  pf->close();
  delete pf;
  pfi->close();
  delete pfi;
  this->UpdateForm();
  this->ButtonNavIdxAnt->Enabled = false;
  this->ButtonNavIdxSig->Enabled = false;
  this->ButtonNavIdxFin->Enabled = false;
  this->ButtonNavIdxIni->Enabled = true;
}
//---------------------------------------------------------------------------

void TForm1::OrdenarIdxCodigo(){
	RegIdxCod ireg, jreg, menReg;
	Cardinal i, j, menPos, ultPosValida;
	fstream fi(nomArchIdxCod.c_str(), ios::in | ios::out | ios::binary);
	if ( !fi.fail() ) {
	  fi.seekg(-1*sizeof(RegIdxCod), ios::end); //ojo: puede que el file este vacio
	  ultPosValida = fi.tellg();
	  i=0;
	  while (i < ultPosValida) {
		fi.seekg(0, ios::beg);
		fi.seekg(i);
		fi.read((char*)&ireg, sizeof(ireg));
		if ( !fi.eof()){ //guardar el primer registro
		  menPos = i;
		  menReg = ireg;
		}
		while ( !fi.eof() ) { //buscar el proximo menor
		  j = fi.tellg();
		  fi.read((char*)&jreg, sizeof(jreg));
		  if ( !fi.eof() && jreg.cod < menReg.cod ){
			  menPos = j;
			  menReg = jreg;
		  }
		}
		if ( i != menPos){ //permutas posiciones
			fi.seekg(0, ios::beg);
			fi.seekg(i);
			fi.write((char*)&menReg, sizeof(menReg));
			fi.seekg(menPos);
			fi.write((char*)&ireg, sizeof(ireg));
		}
		i = i + sizeof(ireg);
	  }
	}
	fi.close();
}

void TForm1::OrdenarIdxFecha(){
	RegIdxFecha ireg, jreg, menReg;
	Cardinal i, j, menPos, ultPosValida;
	fstream fi(nomArchIdxFecha.c_str(), ios::in | ios::out | ios::binary);
	if ( !fi.fail() ) {
	  fi.seekg(-1*sizeof(ireg), ios::end); //ojo: puede que el file este vacio
	  ultPosValida = fi.tellg();
	  i=0;
	  while (i < ultPosValida) {
		fi.seekg(0, ios::beg);
		fi.seekg(i);
		fi.read((char*)&ireg, sizeof(ireg));
		if ( !fi.eof()){ //guardar el primer registro
		  menPos = i;
		  menReg = ireg;
		}
		while ( !fi.eof() ) { //buscar el menor
		  j = fi.tellg();
		  fi.read((char*)&jreg, sizeof(jreg));
		  if ( !fi.eof() && jreg.fecha.dia < menReg.fecha.dia  ){
			  menPos = j;
			  menReg = jreg;
		  }
		}
		if ( i != menPos){ //permutas posiciones
			fi.seekg(0, ios::beg);
			fi.seekg(i);
			fi.write((char*)&menReg, sizeof(menReg));
			fi.seekg(menPos);
			fi.write((char*)&ireg, sizeof(ireg));
		}
		i = i + sizeof(ireg);
	  }
	}
	fi.close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::createCodigoClick(TObject *Sender){
  RegIdxCod regIdx;
  RegAlumno reg;
  AnsiString linea;
  fstream f(nomArch.c_str(), ios::in | ios::binary);
  fstream fi(nomArchIdxCod.c_str(), ios::in | ios::binary);
  fstream ft("listado-alumnos.txt", ios::out);
  if ( !fi.fail() ) {
	linea = "LISTADO DE ALUMNOS\nCOD\tNOM";
	for (Word i =1; i <=  linea.Length(); i++) {
	  ft.put(linea[i]);
	}
	ft.put(10);
	while ( !fi.eof() ) {
	  fi.read((char*) &regIdx, sizeof(regIdx));
	  if ( !fi.eof()) {
		f.seekg(regIdx.pos, ios::beg);		
		f.read((char*) &reg, sizeof(reg));
		linea = IntToStr(reg.cod) +"\t"+ reg.nom;
		for (Word i =1; i <=  linea.Length(); i++) {
	      ft.put(linea[i]);
		}
		ft.put(10);
	  }
	}
  }
  f.close();
  fi.close();
  ft.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::onClickCreateMonthFile(TObject *Sender)
{
  fstream fa(
	this->nomArch.c_str(),
	ios::in
  );
  fstream fb(
	"listado.txt",
	ios::out
  );
  if(!fa.fail()){
	  RegAlumno reg;
	  AnsiString line;
	  byte searchMonth = StrToInt(InputBox("mes","ingrese",""));
	  while ( !fa.eof() ) {
		fa.read((char*)&reg, sizeof(reg));
		if ( !fa.eof() && (reg.fecha.mes == searchMonth) ) {
		  line =   IntToStr(reg.cod)+"\t"+
				   reg.nom + "\t"+
				   reg.dir + "\t"+
				   IntToStr(reg.fecha.dia) + "/" +
				   IntToStr(reg.fecha.mes) + "/" +
				   IntToStr(reg.fecha.año);
		  for (byte i = 1; i <= line.Length(); i++) {
			fb.put(line[i]);
		  }
		  fb.put(10);
		}
	  }
	  fa.close();
	  fb.close();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::onClickLoad(TObject *Sender)
{
  pf = new fstream(nomArch.c_str(), ios::trunc | ios::out | ios::binary);
//  if( !pf->is_open() ){
//	this->pf->open(this->nomArch.c_str(), ios::in | ios::out | ios::binary);
//  }
  if( this->pf->fail() ) {
	ShowMessage("ocurrio un error");
	return;
  }
  RegAlumno alumnos[] = {
//	RegAlumno(140, "maria", "c3", TFecha(7,12,2000)),
//	RegAlumno(150, "josefa", "c4", TFecha(8,2,2002)),
//	RegAlumno(160, "roberto", "c5", TFecha(10,10,2010)),
//	RegAlumno(130, "pedro", "c2", TFecha(4,2,1993)),
//	RegAlumno(170, "betty", "c6", TFecha(6,2,2004)),
//	RegAlumno(180, "mario", "c7", TFecha(5,6,2007)),
//	RegAlumno(120, "Juan", "c1", TFecha(2,1,1995))

//	RegAlumno(120, "Juan", "c1", TFecha(20,1,1972)),
//	RegAlumno(130, "Pedro", "c2", TFecha(21,02,1982)),
//	RegAlumno(140, "María", "c3", TFecha(21,04,1992)),
//	RegAlumno(150, "Josefa", "c4", TFecha(22,2,1995)),
//	RegAlumno(160, "Roberto", "c5", TFecha(23,3,1999)),
//	RegAlumno(170, "Josué", "c6", TFecha(24,06,2000)),
//	RegAlumno(180, "Betty", "c7", TFecha(25,04,2005)),

	RegAlumno(150, "Pedro", "c1", TFecha(29,02,2001)),
	RegAlumno(120, "María", "c2", TFecha(15,04,2000)),
	RegAlumno(160, "Jose", "c3", TFecha(10,3,2002)),
	RegAlumno(130, "Betty", "c4", TFecha(20,6,2003)),
	RegAlumno(140, "Jorge", "c5", TFecha(17,5,2002)),
	RegAlumno(170, "Jacinto", "c6", TFecha(20,2,2001)),
  };
  int n = sizeof(alumnos) / sizeof(alumnos[0]);
  for (byte i = 0; i < n; i++) {
	pf->write((char *)&alumnos[i], sizeof(alumnos[i]));
  }
  pf->close();
}
//---------------------------------------------------------------------------
char ToLower(char x){
  AnsiString MAY = "QWERTYUIOPASDFGHJKLZXCVBNMÑ"; //a..z
  AnsiString MIN = "qwertyuiopasdfghjklzxcvbnmñ";
  byte p = MAY.Pos(x);
  return    (p == 0)
			? x
			: MIN[p];
}


bool compare(AnsiString searchName, char nom[21]){
   AnsiString name = "";
   char x;
   byte i = 0;
   while (i < 21 &&   //dentro del array
		(i+1<=searchName.Length()) &&  //dentro de la cadena
		ToLower(searchName[i+1]) == ToLower(nom[i])) {//mientras son caracteres iguales
	 i++;
   }
   return (i+1>searchName.Length());
}

Word searchName(AnsiString NameFile){
  fstream fa(NameFile.c_str(),	ios::in);
  RegAlumno reg;
  Word cod = 0;
  if(!fa.fail()){
	  AnsiString searchName = InputBox("ingrese","Nombre","");
	  fa.read((char*)&reg, sizeof(reg));
	  while (  !fa.eof() && !(compare(searchName, reg.nom)) ) {
		fa.read((char*)&reg, sizeof(reg));
	  }

	  //opcion1
//	  if(!fa.eof()) cod=reg.cod;

	  //opcion2
	  cod = (!fa.eof()) ? reg.cod : 0;

	  //opcion3
//	  if (!fa.eof()) {
//		cod = reg.cod;
//	  } else {
//		cod = 0;
//	  }
	  fa.close();
  }
  return cod;
}
void __fastcall TForm1::onClickSearchName(TObject *Sender)
{
  Word salida = searchName(this->nomArch);
  ShowMessage(IntToStr(salida));
}
//---------------------------------------------------------------------------
void TForm1::CreateIndexCodigo(){
	RegAlumno reg;
	RegIdxCod regIdx;
	fstream f(nomArch.c_str(), ios::in | ios::binary);
	fstream fi(nomArchIdxCod.c_str(), ios::out | ios::binary);
	if ( !f.fail() ) {
		while ( !f.eof() ) {
		  regIdx.pos = f.tellg();
		  f.read((char *)&reg, sizeof(reg));
		  if (!f.eof()) {
			regIdx.cod = reg.cod;
			fi.write((char *)&regIdx, sizeof(regIdx));
		  }
		}
	}
	f.close();
	fi.close();
}

void TForm1::CreateIndexFecha(){
	RegAlumno reg;
	RegIdxFecha regIdx;
	fstream f(nomArch.c_str(), ios::in | ios::binary);
	fstream fi(nomArchIdxFecha.c_str(), ios::out | ios::binary);
	if ( !f.fail() ) {
		while ( !f.eof() ) {
		  regIdx.pos = f.tellg();
		  f.read((char *)&reg, sizeof(reg));
		  if (!f.eof()) {
			regIdx.fecha = reg.fecha;
			fi.write((char *)&regIdx, sizeof(regIdx));
		  }
		}
	}
	f.close();
	fi.close();
}


void __fastcall TForm1::searchMenByIndex(TObject *Sender){
  RegIdxFecha regIdx;
  RegAlumno reg, resp;
  fstream f(nomArch.c_str(), ios::in | ios::binary);
  fstream fi(nomArchIdxFecha.c_str(), ios::in | ios::binary);
  bool sw = true;
  if ( !fi.fail() ) {
	while ( !fi.eof() ) {
	  fi.read((char*) &regIdx, sizeof(regIdx));
	  if ( !fi.eof()) {
		f.seekg(regIdx.pos, ios::beg);
		f.read((char*) &reg, sizeof(reg));
		if(!f.eof()){
		  if (sw) {
			resp = reg;
			sw = false;
		  }else if(reg.fecha.año < resp.fecha.año
		   || (reg.fecha.año == resp.fecha.año && reg.fecha.mes < resp.fecha.mes)
		   || (reg.fecha.año == resp.fecha.año && reg.fecha.mes == resp.fecha.mes && reg.fecha.dia < resp.fecha.dia)
		   ){
			resp = reg;
		  }
		}
	  }
	}
  }
  f.close();
  fi.close();
  ShowMessage(resp.ToString());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::searchBinaryCodeByIndex(TObject *Sender){
	RegIdxCod reg;
	Cardinal a, b, m ;
	Cardinal cod = InputBox("Numero?","","").ToInt();
	fstream fi(nomArchIdxCod.c_str(), ios::in | ios::out | ios::binary);
	if ( !fi.fail() ) {
	  fi.seekg(-1*sizeof(RegIdxCod), ios::end); //ojo: puede que el file este vacio
	  a = 0;
	  b = fi.tellg();
	  while (a <= b) {
		m = (a + b) / 2;
		fi.seekg(0, ios::beg);
		fi.seekg(m);
		fi.read((char*)&reg, sizeof(reg));
		if ( !fi.eof()){
			if (reg.cod == cod) {
			  ShowMessage("true");
			  return;
			} else if(cod < reg.cod){
			  b = m - sizeof(reg);
			} else {
			  a = m + sizeof(reg);
			}
		}
	  }
	}
	fi.close();
	ShowMessage("false");
}
//---------------------------------------------------------------------------


//paso 1 - crear archivo indexado por fecha

//paso 2 ordenar archivo indexado fecha por dia

//paso 3 - exportar archivo txt
void __fastcall TForm1::pregunta2(TObject *Sender)
{
  RegIdxFecha regIdx;
  RegAlumno reg;
  AnsiString linea;
  fstream f(nomArch.c_str(), ios::in | ios::binary);
  fstream ft("ArchivoListado.txt", ios::out);
  if ( !f.fail() ) {
	linea = "LISTADO DE ALUMNOS";
	for (Word i =1; i <=  linea.Length(); i++) {
	  ft.put(linea[i]);
	}
	ft.put(10);
	while ( !fi.eof() ) {
	  if ( !fi.eof()) {
		f.seekg(regIdx.pos, ios::beg);
		f.read((char*) &reg, sizeof(reg));
		linea = IntToStr(reg.cod) +", "+ reg.nom + ", " + reg.fecha.ToString();
		for (Word i =1; i <=  linea.Length(); i++) {
		  ft.put(linea[i]);
		}
		ft.put(10);
	  }
	}
  }
  f.close();
  ft.close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ComboBoxCreateIdxChange(TObject *Sender){
  byte p = ComboBoxCreateIdx->ItemIndex;
  switch (p) {
	case 1:
		this->CreateIndexCodigo();
		break;
	case 2:
		//nombre
		break;
	case 3:
		//direccion
		break;
	case 4:
		CreateIndexFecha();
		break;
	case 5:
		//telefono
		break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBoxOrdenarIdxChange(TObject *Sender){
  byte p = ComboBoxOrdenarIdx->ItemIndex;
  switch (p) {
	case 1:  //codigo
		this->OrdenarIdxCodigo();
		break;
	case 2: //nombre

		break;
	case 3: //direccion

		break;
	case 4:  //fecha
		this->OrdenarIdxFecha();
		break;
	case 5:  //telefono
		break;
  }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ComboBoxExportIdxChange(TObject *Sender){
  byte p = ComboBoxExportIdx->ItemIndex;
  switch (p) {
	case 1:  //codigo
//		this->exportarIdxCodigo();
		break;
	case 2: //nombre

		break;
	case 3: //direccion

		break;
	case 4:  //fecha
//		this->exportarIdxCodigoIdxFecha()
		break;
	case 5:  //telefono
		break;
  }
}
//---------------------------------------------------------------------------
Cardinal GetNumero(Word year){
  Word cantDig = log10((double)year*10);
  return 6543 * (pow10(cantDig)) + year;
}
void pregunta1(AnsiString nameFile){
	RegAlumno regAct, regAnt;
	AnsiString nameTmp = "temporal.tmp";
	fstream fe(nameFile.c_str(), ios::in | ios::binary);
	fstream fs(nameTmp.c_str(), ios::trunc | ios::out | ios::binary);
	bool sw = true;
	if ( !fe.fail() ) {
		fe.read((char*)&regAct, sizeof(regAct));
		while( !fe.eof()) {
		  if (sw) {
			regAct.telefono = 6543 * 1000;
			sw = false;
		  } else {
			regAct.telefono = GetNumero(regAnt.fecha.año);
		  }
		  fs.write((char *)&regAct, sizeof(regAct));
		  regAnt = regAct;
		  fe.read((char*)&regAct, sizeof(regAct));
		};
	}
	fe.close();
	fs.close();
	remove(nameFile.c_str());
	rename(nameTmp.c_str(),nameFile.c_str());
}
//llamada al algoritmo
void __fastcall TForm1::Button3Click(TObject *Sender){
  pregunta1(this->nomArch);
}
//---------------------------------------------------------------------------

