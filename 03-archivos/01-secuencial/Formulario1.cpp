//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Formulario1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
/*variable global*/
	AnsiString fileName, globalName2;
	AnsiString names[2] = {"",""};
	//TOpenTextFileDialog *openDialog;
	//struct Data {AnsiString name;};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
  OpenTextFileDialog1->InitialDir = "G:\\auxiliar\\INF210\\INF210\\03-archivos\\01-secuencial\\files";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SelectClick(TObject *Sender)
{

  if (OpenTextFileDialog1->Execute()) {
	fileName = OpenTextFileDialog1->FileName;
	//	ShowMessage(names[i]);
  }
  //  ShowMessage(IntToStr(ComboBox1->ItemIndex));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSelectClick(TObject *Sender)
{
  if (OpenTextFileDialog1->Execute()) {
	  Edit1->Text = GetCantVocales(
		OpenTextFileDialog1->FileName
	  );
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LimpiarVocSigClick(TObject *Sender)
{
  Limpiar(fileName);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::crearNivel21Form(TObject *Sender)
{
  AnsiString x = "nivel21.txt";
  CrearNivel21V2(fileName, x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VerificarNivel21Click(TObject *Sender)
{
  bool sw = VerifNivel21(fileName);
  AnsiString salida = (sw)? ("Formato Ok") : ("Formato Erroneo");
  ShowMessage(salida);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::onSearchAndReplace(TObject *Sender)
{
//  AnsiString search = Edit1->Text;
//  AnsiString replace = Edit2->Text;
  AnsiString search = "maria jose";
  AnsiString replace = "ramiro";
  if (OpenTextFileDialog1->Execute()) {
	SearchAndReplace(
		OpenTextFileDialog1->FileName,
		search,
		replace
	);
  }
}
//---------------------------------------------------------------------------

