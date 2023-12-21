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
	: TForm(Owner){}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender){
  OpenTextFileDialog1->InitialDir = "G:\\auxiliar\\INF210\\INF210\\03-archivos\\01-secuencial\\files";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSelectClick(TObject *Sender){
  if( !(OpenTextFileDialog1->Execute())) return;
  Edit1->Text = GetCantVocales( OpenTextFileDialog1->FileName );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LimpiarVocSigClick(TObject *Sender){
  if( !OpenTextFileDialog1->Execute()) return;
  Limpiar( OpenTextFileDialog1->FileName );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::crearNivel21Form(TObject *Sender){
  if( !OpenTextFileDialog1->Execute()) return;
  AnsiString x = "nivel21.txt";
  CrearNivel21V2(OpenTextFileDialog1->FileName, x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VerificarNivel21Click(TObject *Sender){
  if( !OpenTextFileDialog1->Execute()) return;
  bool sw = VerifNivel21(OpenTextFileDialog1->FileName);
  AnsiString salida = (sw)? ("Formato Ok") : ("Formato Erroneo");
  ShowMessage(salida);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::onSearchAndReplace(TObject *Sender){
  if( !OpenTextFileDialog1->Execute()) return;
//  AnsiString search = Edit1->Text;
//  AnsiString replace = Edit2->Text;
  AnsiString search = "maria jose";
  AnsiString replace = "ramiro";
  SearchAndReplace(
	OpenTextFileDialog1->FileName,
	search,
	replace
  );
}
//---------------------------------------------------------------------------

