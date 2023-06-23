//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Formulario1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool EsVocal(char x){
  AnsiString vocales = "aeiouáéíóúäüöAEIOUÁÉÍÓÚ";
  return vocales.Pos(x) > 0;
}

Cardinal GetCantVocales(AnsiString nameFile){
  Cardinal cv;
  char x;
  ifstream f(nameFile.c_str());
  cv = 0;
  if ( !f.fail()) {
	while ( !f.eof()) {
	  x = f.get();
	  if ( !f.eof() && EsVocal(x))
		cv++;
	}
  }  
  f.close();
  return cv;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if (OpenTextFileDialog1->Execute()) {
	AnsiString name = OpenTextFileDialog1->FileName;
	Edit1->Text = GetCantVocales(name);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  OpenTextFileDialog1->InitialDir = "G:\auxiliar\INF210\INF210\03-archivos\01";		
  
}
//---------------------------------------------------------------------------

