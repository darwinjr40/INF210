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
	pf = new fstream(nomArch.c_str(),ios::in|ios::binary);
	if (pf->fail()){
	  delete pf;
	  pf = new fstream(nomArch.c_str(),ios::out|ios::binary);
	}
	pf->close();
	delete pf;
}
//---------------------------------------------------------------------------
void TForm1::UpdateForm(AnsiString cod,AnsiString nom,AnsiString dir, AnsiString fecha){
  Edit1->Text = (cod==NULL)? (AnsiString)Edit1->Text : cod;
  Edit2->Text = (nom==NULL)? (AnsiString)Edit1->Text :nom;
  Edit3->Text = (dir==NULL)? (AnsiString)Edit1->Text :dir;
  MaskEdit1->Text = (fecha==NULL)? (AnsiString)Edit1->Text :fecha;
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
		  UpdateForm(NULL,"","","");
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
		UpdateForm("","","","");
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
		reg = RegAlumno(300, "Juan Perez", "calle 123", TFecha(10,10,1010));
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
	const byte n = 5;
	AnsiString datos[n] = {"cod", "nombre", "direccion", "fecha", "marca"};
	byte c = 0;

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
  RegAlumnoV1 regAnt;
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
		 UpdateForm("","","","");
	  }
  }
  f.close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::codgio1Click(TObject *Sender){
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
	}             //| ios::trunc
	f.close();
	fi.close();
}
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
  this->ButtonNavIdxAnt->Enabled = false;
  this->ButtonNavIdxSig->Enabled = false;
  this->ButtonNavIdxFin->Enabled = false;
  this->ButtonNavIdxIni->Enabled = true;
}
//---------------------------------------------------------------------------
void permutar(fstream &fi, Cardinal pa, RegIdxCod ra, Cardinal pb, RegIdxCod rb){
	fi.seekg(0, ios::beg);
	fi.seekg(pa);
	fi.write((char*)&rb, sizeof(rb));
	fi.seekg(pb);
	fi.write((char*)&ra, sizeof(ra));
}

void __fastcall TForm1::codigo1Click(TObject *Sender){
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
		if ( i != menPos) permutar(fi, i,ireg, menPos,menReg);
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
  if(fa.fail()) return;
  RegAlumno reg;
  AnsiString line;
  byte searchMonth = StrToInt(InputBox("","",""));
  while ( !fa.eof() ) {
	fa.read((char*)&reg, sizeof(reg));
	if ( !fa.eof() && (reg.fecha.mes == searchMonth) ) {
	  line = reg.ToLine();
	  for (byte i = 1; i <= line.Length(); i++) {
		fb.put(line[i]);  			
	  }
	  fb.put(10);
	}	
  }
  fa.close();
  fb.close();  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::onClickLoad(TObject *Sender)
{
  pf = new fstream(nomArch.c_str(), ios::in | ios::out | ios::binary);
//  if( !pf->is_open() ){
//	this->pf->open(this->nomArch.c_str(), ios::in | ios::out | ios::binary);
//  }
  if( this->pf->fail() ) return;
  const byte n = 7;
  RegAlumno alumnos[n] = {
	RegAlumno(120, "Juan", "c1", TFecha(2,1,95)),
	RegAlumno(130, "pedro", "c2", TFecha(4,2,93)),
	RegAlumno(140, "maria", "c3", TFecha(7,12,0000)),
	RegAlumno(150, "josefa", "c4", TFecha(8,2,02)),
	RegAlumno(160, "roberto", "c5", TFecha(10,10,10)),
	RegAlumno(170, "betty", "c6", TFecha(6,2,04)),
	RegAlumno(180, "mario", "c7", TFecha(5,6,07))
  };
  RegAlumno reg;
  for (byte i = 0; i < n; i++) {
	reg = alumnos[i];
	pf->write((char *)&reg, sizeof(reg));
  }  
  pf->close();
}
//---------------------------------------------------------------------------

