//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Formulario1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
/*variable global*/
	AnsiString globalName1, globalName2;
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
	int i = ComboBox1->ItemIndex;
	names[i] = OpenTextFileDialog1->FileName;
	//	ShowMessage(names[i]);
  }
  //  ShowMessage(IntToStr(ComboBox1->ItemIndex));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSelectClick(TObject *Sender)
{
  Edit1->Text = GetCantVocales(names[0]);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LimpiarVocSigClick(TObject *Sender)
{
  Limpiar(names[0]);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::crearNivel21Form(TObject *Sender)
{
  AnsiString x = "nivel21.txt";
  CrearNivel21V2(names[0], x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VerificarNivel21Click(TObject *Sender)
{
  bool sw = VerifNivel21(names[0]);
  AnsiString salida = (sw)? ("Formato Ok") : ("Formato Erroneo");
  ShowMessage(salida);
}
//---------------------------------------------------------------------------

