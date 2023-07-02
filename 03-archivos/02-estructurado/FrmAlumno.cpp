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
	if (!pf->fail()) {
		pf->read((char*)&reg, sizeof(reg));
		while( !pf->eof() && (reg.cod != cod) ) {
		  ShowMessage(reg.ToString());  //		hallado = (reg.cod == codi) && (reg.mark != '*');
		  pf->read((char*)&reg, sizeof(reg));
		};
		if (pf->eof()) //es fin de archivo
		  UpdateForm(NULL,"","","");
		else
		  UpdateForm(IntToStr(reg.cod), reg.nom, reg.dir,reg.fecha.ToString());
	}
	pf->close();
	delete pf;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	RegAlumno reg, regNuevo;
	regNuevo.cod = StrtoInt(Edit1->Text);
	strcpy(regNuevo.nom, (AnsiString(Edit2->Text)).c_str());
	strcpy(regNuevo.dir,(AnsiString(Edit3->Text)).c_str());
	regNuevo.fecha = TFecha(StrtoInt(MaskEdit1->Text.SubString(1, 2)), StrtoInt(MaskEdit1->Text.SubString(4, 2)), StrtoInt(MaskEdit1->Text.SubString(7, 4)));
	pf = new fstream(nomArch.c_str(), ios::in | ios::out | ios::binary);
	if (pf->is_open()) {
		pf->read((char*)&reg, sizeof(reg));
		while( !pf->eof() && (reg.cod != regNuevo.cod) ) {
		  pf->read((char*)&reg, sizeof(reg));
		};
		if (pf->eof())  //add
		  pf->seekg(0,ios::end);
		else //update
		  pf->seekg(-sizeof(reg), ios::cur);
		pf->write((char *)&regNuevo, sizeof(regNuevo));
		pf->flush();
		UpdateForm("","","","");
	}
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
		(f.read((char*)&reg, sizeof(reg)));
		(f.read((char*)&reg, sizeof(reg)));

		// Aquí estaba el error: se debe crear el nuevo registro antes de realizar la escritura
		reg = RegAlumno(200, "Juan Perez", "calle 123", TFecha(10,10,1010));
		ShowMessage(IntToStr(f.tellg()));
		f.seekp(-sizeof(reg),ios::cur);
		ShowMessage(IntToStr(f.tellg()));
		ShowMessage(IntToStr(f.tellp()));
		f.write((char*)&reg, sizeof(reg));
		ShowMessage(IntToStr(f.tellg()));
		ShowMessage(IntToStr(f.tellp()));
//		f.seekg(0,ios::cur);
		f.seekg(f.tellg());
		(f.read((char*)&reg, sizeof(reg)));
		(f.read((char*)&reg, sizeof(reg)));

		reg = RegAlumno(200, "Juan Perez", "calle 123", TFecha(10,10,1010));
		f.seekp(-sizeof(reg),ios::cur);
		f.write((char*)&reg, sizeof(reg));

		f.seekg(f.tellg());
		(f.read((char*)&reg, sizeof(reg)));
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
		  ShowMessage(reg.ToString());
	}
	f.close();
}
//---------------------------------------------------------------------------


