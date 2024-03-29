﻿//---------------------------------------------------------------------------

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
	nomArchIdxNom = "nombre.idx";
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

void __fastcall TForm1::Button1Click(TObject *Sender)
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
////		f.seekp(0*sizeof(reg),ios::beg);
//		f.seekp(2*sizeof(reg),ios::beg);
//		f.write((char*)&reg, sizeof(reg));

		reg = RegAlumno(200, "Juan 200", "calle 123", TFecha(10,10,1010));
		f.seekg(1*sizeof(reg),ios::beg);
		f.write((char*)&reg, sizeof(reg));

		reg = RegAlumno(100, "Juan 100", "calle 123", TFecha(10,10,1010));
		f.seekg(0* sizeof(reg),ios::beg);
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

	RegIdxNombre reg;
	fstream f( nomArchIdxNom.c_str(), ios::in | ios::binary);
//	RegAlumnoNew reg;
//	fstream f( AnsiString("AlumnosNew.dat").c_str(), ios::in | ios::binary);
	if ( !f.fail() ) {
		while(f.read((char*)&reg, sizeof(reg)))
		  ShowMessage(reg.ToString());
//		  ShowMessage(IntToStr(reg.cod)+", " +reg.pos);
	}                           //(AnsiString)
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
	const byte n = 6;
	AnsiString datos[n] = {"nro", "cod", "nombre", "direccion", "fecha", "marca"};
	byte c = 1;

	RegAlumno reg;
	fstream fi(nomArch.c_str(), ios::in | ios::binary);
	if ( !fi.fail() ) {
		while(fi.read((char*)&reg, sizeof(reg))) {		  
		  StringGrid1->Cells[0][c] = c-1;		  
		  StringGrid1->Cells[1][c] = reg.cod;
		  StringGrid1->Cells[2][c] = reg.nom;
		  StringGrid1->Cells[3][c] = reg.dir;
		  StringGrid1->Cells[4][c] = reg.fecha.ToString();
		  StringGrid1->Cells[5][c] = reg.marca;
		  c++;
		};
	}
	fi.close();

	for (byte i = 0; i < n; i++) {
	   StringGrid1->Cells[i][0] = datos[i];
	}
//	delete[] datos;
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = c;
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

void __fastcall TForm1::Button2Click(TObject *Sender)
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
		  if ( !f.eof() ) {
			regIdx.cod = reg.cod;
			fi.write((char *)&regIdx, sizeof(regIdx));
		  }
		}
	}
	f.close();
	fi.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxIniClick(TObject *Sender){
	byte p = ComboBox1->ItemIndex;

	if (p == 0) { //codigo
		RegIdxCod regIdx;
		RegAlumno regA;
		pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
		pfIdx = new fstream(nomArchIdxCod.c_str(), ios::in | ios::binary);
		if ( pfIdx->is_open() ) {
			pfIdx->read((char*)&regIdx, sizeof(regIdx));
			if ( !pfIdx->eof() ) {
				pf->seekg(regIdx.pos, ios::beg);
				pf->read((char *)&regA, sizeof(regA));
				this->UpdateForm(IntToStr(regA.cod), regA.nom, regA.dir, regA.fecha.ToString());
				this->ButtonNavIdxSig->Enabled = true;
				this->ButtonNavIdxAnt->Enabled = true;
				this->ButtonNavIdxFin->Enabled = true;
			}
		}
		this->ButtonNavIdxIni->Enabled = false;	
			
	} else if(p==1){  //nombre
	
		RegIdxNombre regIdx;
		RegAlumno regA;
		pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
		pfIdx = new fstream(nomArchIdxNom.c_str(), ios::in | ios::binary);
		if ( pfIdx->is_open() ) {
			pfIdx->read((char*)&regIdx, sizeof(regIdx));
			if ( !pfIdx->eof() ) {
				pf->seekg(regIdx.pos, ios::beg);
				pf->read((char *)&regA, sizeof(regA));
				this->UpdateForm(IntToStr(regA.cod), regA.nom, regA.dir, regA.fecha.ToString());
				this->ButtonNavIdxSig->Enabled = true;
				this->ButtonNavIdxAnt->Enabled = true;
				this->ButtonNavIdxFin->Enabled = true;
			}
		}
		this->ButtonNavIdxIni->Enabled = false;
		
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxSigClick(TObject *Sender){
	byte p = ComboBox1->ItemIndex;
	if (p == 0) { //codigo	
		RegIdxCod regIdx;
		RegAlumno regA;
		if ( pfIdx->is_open() ) {
			ButtonNavIdxAnt->Enabled = true;
			pfIdx->read((char*)&regIdx, sizeof(regIdx));
			if ( pfIdx->eof() ) {
				pfIdx->close();
				delete pfIdx;
				pfIdx = new fstream(nomArchIdxCod.c_str(), ios::in | ios::binary);
				pfIdx->seekg(0, ios::end);
				ButtonNavIdxSig->Enabled = false;
			} else {
				pf->seekg(regIdx.pos, ios::beg);
				pf->read((char *)&regA, sizeof(regA));
				this->ShowAlumno(regA);
				ButtonNavIdxSig->Enabled = true;
			}
		}

	} else if(p==1){
	
		RegIdxNombre regIdx;
		RegAlumno regA;
		if ( pfIdx->is_open() ) {
			ButtonNavIdxAnt->Enabled = true;
			pfIdx->read((char*)&regIdx, sizeof(regIdx));
			if ( pfIdx->eof() ) {
				pfIdx->close();
				delete pfIdx;
				pfIdx = new fstream(nomArchIdxCod.c_str(), ios::in | ios::binary);
				pfIdx->seekg(0, ios::end);
				ButtonNavIdxSig->Enabled = false;
			} else {
				pf->seekg(regIdx.pos, ios::beg);
				pf->read((char *)&regA, sizeof(regA));
				this->ShowAlumno(regA);
				ButtonNavIdxSig->Enabled = true;
			}
		}
		
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxAntClick(TObject *Sender){
	byte pc = ComboBox1->ItemIndex;
	if (pc == 0) { //codigo

		RegIdxCod regIdx;
		RegAlumno regA;
		Cardinal p;
		if ( pfIdx->is_open() ) {
			p = pfIdx->tellg();
			if (p <= sizeof(regIdx)) { // si esta en el primer registro del idx
				ButtonNavIdxAnt->Enabled = false;
			} else {
				pfIdx->seekg(-2*sizeof(regIdx), ios::cur);
				pfIdx->read((char*)&regIdx, sizeof(regIdx));
				if ( !pfIdx->eof() ) {
					pf->seekg(regIdx.pos, ios::beg);
					pf->read((char *)&regA, sizeof(regA));
					this->UpdateForm(IntToStr(regA.cod), regA.nom, regA.dir, regA.fecha.ToString());
					ButtonNavIdxAnt->Enabled = true;
					ButtonNavIdxSig->Enabled = true;
				}
			}
		}

	} else if(pc == 1){
		RegIdxNombre regIdx;
		RegAlumno regA;
		Cardinal p;
		if ( pfIdx->is_open() ) {
			p = pfIdx->tellg();
			if (p <= sizeof(regIdx)) { // si esta en el primer registro del idx
				ButtonNavIdxAnt->Enabled = false;
			} else {
				pfIdx->seekg(-2*sizeof(regIdx), ios::cur);
				pfIdx->read((char*)&regIdx, sizeof(regIdx));
				if ( !pfIdx->eof() ) {
					pf->seekg(regIdx.pos, ios::beg);
					pf->read((char *)&regA, sizeof(regA));
					this->UpdateForm(IntToStr(regA.cod), regA.nom, regA.dir, regA.fecha.ToString());
					ButtonNavIdxAnt->Enabled = true;
					ButtonNavIdxSig->Enabled = true;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNavIdxFinClick(TObject *Sender)
{
  pf->close();	
  delete pf;
  pfIdx->close();
  delete pfIdx;
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
	RegIdxCod ireg, jreg, kreg;
	Cardinal i, j, k;
	fstream fi(nomArchIdxCod.c_str(), ios::in | ios::out | ios::binary);
	if ( !fi.fail() ) {
	  i=0; j=1;
	  while (i < j) {
		j=i;
		fi.seekg(0, ios::beg);
		fi.seekg(0, ios::beg);
		fi.seekg(j);
		while ( !fi.eof() ) {
		  j = fi.tellg();
		  fi.read((char*)&jreg, sizeof(jreg));
		  if ( !fi.eof()) {
			if (j==i) {
			  k = j;
			  kreg = jreg;
			  ireg = jreg;
			} else if(jreg.cod > kreg.cod){
			  k = j;
			  kreg = jreg;
			}
		  }
		}
		if ( i != k) permutar(fi, i,ireg,k,kreg);
		i = i + sizeof(ireg);
		j = j - sizeof(jreg);
	  }
	}
	fi.close();

  //version-darwin
//	RegIdxCod ireg, jreg, kreg;
//	Cardinal i, j, k;
//	fstream fi(nomArchIdxCod.c_str(), ios::in | ios::out | ios::binary);
//	if ( !fi.fail() ) {
//	  i=0; j=1;
//	  while (i < j) {
//		j=i;
//		fi.seekg(0, ios::beg);
//		fi.seekg(j);
//		if (fi.read((char*)&jreg, sizeof(jreg))) {
//		  k = j;
//		  kreg = jreg;
//		  ireg = jreg;
//		}
//		while ( !fi.eof() ) {
//		  fi.read((char*)&jreg, sizeof(jreg));
//		  if ( !fi.eof() && (jreg.cod > kreg.cod)) {
//			  k = fi.tellg();
//			  kreg = jreg;
//		  }
//		}
//		if ( i != k) permutar(fi, i,ireg,k,kreg);
//		i = i + sizeof(ireg);
//		j = j - sizeof(jreg);
//	  }
//	}
//	fi.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::general1Click(TObject *Sender){

	RegAlumno reg;
	fstream f(regIdx.nomArch.c_str(), ios::in | ios::binary);
	fstream fi(nomArchIdxCod.c_str(), ios::out | ios::binary);
//	IRegIdx& regidx = *regIdx.reg;
	if ( !f.fail() ) {	
		while ( !f.eof() ) {
		  regIdx.reg->pos = f.tellg();
		  f.read((char *)&reg, sizeof(reg));		
		  if (!f.eof()) {
			regIdx.reg->Copiar(reg);
			fi.write((char *)&*regIdx.reg, regIdx.size);  
		  }
		}
	}
	f.close();
	fi.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender){
//	const byte n = 4;
//	size_t sizes[n] = {sizeof(RegIdxCodV1), sizeof(RegIdxNom),sizeof(RegIdxDir),sizeof(RegIdxFecha)};
//	AnsiString nomArchs[n] = {File::NOM_ARCH_IDX_COD, File::NOM_ARCH_IDX_NOM, File::NOM_ARCH_IDX_DIR, File::NOM_ARCH_IDX_FEC};
//	IRegIdx* regIdxs[n] = {new RegIdxCodV1(), new RegIdxNom(), new RegIdxDir(), new RegIdxFecha()};
//////
//	byte p = ComboBox1->ItemIndex;
//	size = sizes[p];
//	nomArchIdx = nomArchs[p];
//	regIdx =  regIdxs[p];
//
//	for (int i = 0; i < n; i++) {
//		delete regIdxs[i];
//	}
    delete regIdx.reg;
	byte p = ComboBox1->ItemIndex;
	if (p == 0) {
	  regIdx.reg = new RegIdxCodV1();
	  regIdx.size = sizeof(RegIdxCodV1);
	  regIdx.nomArch = "codigo.idx";
	} else if (p == 1) {
	  regIdx.reg = new RegIdxNom();
	  regIdx.size = sizeof(RegIdxNom);
	  regIdx.nomArch = "nombre.idx";	
	} else if (p == 2) {
	  regIdx.reg = new RegIdxDir();
	  regIdx.size = sizeof(RegIdxDir);
	  regIdx.nomArch = "direccion.idx";	
	} else {
	  regIdx.reg = new RegIdxDir();
	  regIdx.size = sizeof(RegIdxDir);
	  regIdx.nomArch = "fecha.idx";		
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::general2Click(TObject *Sender){
  byte pc = ComboBox1->ItemIndex;
  if (pc == 0) {
	RegIdxCod ireg, jreg, kreg;
	Cardinal i, j, k;
	fstream fi(nomArchIdxCod.c_str(), ios::in | ios::out | ios::binary);
	if ( !fi.fail() ) {
	  i=0; j=1;
	  while (i < j) {
		j=i;
		fi.seekg(0, ios::beg);
		fi.seekg(0, ios::beg);
		fi.seekg(j);
		while ( !fi.eof() ) {
		  j = fi.tellg();
		  fi.read((char*)&jreg, sizeof(jreg));
		  if ( !fi.eof()) {
			if (j==i) {
			  k = j;
			  kreg = jreg;
			  ireg = jreg;
			} else if(jreg.cod > kreg.cod){
			  k = j;
			  kreg = jreg;
			}
		  }
		}
		if ( i != k) permutar(fi, i,ireg,k,kreg);
		i = i + sizeof(ireg);
		j = j - sizeof(jreg);
	  }
	}
	fi.close();	
	
  } else if(pc==1){
  
	RegIdxNombre ireg, jreg, kreg;
	Cardinal i, j, k;
	AnsiString jnom, knom;
	fstream fi(nomArchIdxNom.c_str(), ios::in | ios::out | ios::binary);
	if ( !fi.fail() ) {
	  i=0; j=1;
	  while (i < j) {
		j=i;
		fi.seekg(0, ios::beg);
		fi.seekg(0, ios::beg);
		fi.seekg(j);
		while ( !fi.eof() ) {
		  j = fi.tellg();
		  fi.read((char*)&jreg, sizeof(jreg));
		  if ( !fi.eof()) {
			if (j==i) {
			  k = j;
			  kreg = jreg;
			  ireg = jreg;
			} else{
			  jnom = jreg.nom;
			  knom = kreg.nom;
			  if(jnom  < knom){
				k = j;
				kreg = jreg;
			  }			  
			}
			
		  }
		}
		
		if ( i != k){
          	fi.seekg(0, ios::beg);
			fi.seekg(i);
			fi.write((char*)&kreg, sizeof(kreg));
			fi.seekg(k);
			fi.write((char*)&ireg, sizeof(ireg));
		};
		i = i + sizeof(ireg);
		j = j - sizeof(jreg);
	  }
	}
	fi.close();	
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nombre1Click(TObject *Sender)
{
	RegAlumno reg;
	RegIdxNombre regIdx;
	fstream f(nomArch.c_str(), ios::in | ios::binary);
	fstream fi(nomArchIdxNom.c_str(), ios::out | ios::binary);
	if ( !f.fail() ) {
		while ( !f.eof() ) {
		  regIdx.pos = f.tellg();
		  f.read((char *)&reg, sizeof(reg));
		  if ( !f.eof() ) {
			strncpy(regIdx.nom,reg.nom,21); // regIdx.cod = reg.cod;
			fi.write((char *)&regIdx, sizeof(regIdx));
		  }
		}
	}
	f.close();
	fi.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
//   byte p = ComboBox2->ItemIndex;
//   ShowMessage(p);
}
//---------------------------------------------------------------------------

