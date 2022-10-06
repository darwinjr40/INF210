//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form.h"
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
/*
EL METODO YA SEA FUNCION O PROCEDIMIENTO
*/

void __fastcall TForm1::eliminarprimeraletradecadapalabra1Click(TObject *Sender)
{
  AnsiString cad = Edit1->Text;
//DeleteUltimoCaracterDeUnaPalabraV2(cad, 2);
  DeletePrimerCaracterDeUnaPalabra(cad);
  Edit2->Text = cad;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::prueba1Click(TObject *Sender)
{
	char x = Edit1->Text[1];        //ASCII     AnsiString
	wchar_t y = Edit1->Text[1];     //UNICODE   String

//	Edit2->Text = BoolToStr(EsVocal(x), true);
	if (x == 'ñ') {  //comparaciones de caracteres es a nivel char.
		ShowMessage("ascii");
	}
	if (y == 'ñ') {
		ShowMessage("unicode");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PRIMERNumero1Click(TObject *Sender)
{
  Edit2->Text = primerNum(Edit3->Text);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Numeromayor1Click(TObject *Sender)
{
	String cad = Edit1->Text;
  Edit2->Text =   numMayor(cad);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 StringGrid1->ColCount = Edit1->Text.ToInt();
	 StringGrid1->RowCount = 1;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::generarnumeroconunvector1Click(TObject *Sender)
{
	Word n = StringGrid1->ColCount;
	Cardinal x;
	GenerarNumeroInvertidoV2(StringGrid1, 0, n-1, x);
	ShowMessage(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	StringGrid1->ColCount = Edit2->Text.ToInt();
	StringGrid1->RowCount = Edit1->Text.ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	byte f = StringGrid1->RowCount;
	byte c = StringGrid1->ColCount;
	for (byte i = 0; i < f; i++) {
		for (byte j = 0; j < c; j++) {
		   StringGrid1->Cells[j][i] = "";
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N201931Click(TObject *Sender)
{
  byte fb = StringGrid1->RowCount - 1;
  byte cb = StringGrid1->ColCount - 1;
  byte fa = 0;
  byte ca = 0;
  byte z=1;
  cargarFila2019_32(StringGrid1, fa, fb, ca, cb, z);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N202021Click(TObject *Sender)
{
	if ( !Edit1->Text.IsEmpty()) {
		byte  m = StrToInt(Edit1->Text);
		StringGrid1->ColCount = m;
		StringGrid1->RowCount = m;
		cargarM1(StringGrid1, 0, m - 1, m, 1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N202111Click(TObject *Sender)
{
   if ( !Edit1->Text.IsEmpty()) {
		byte  m = StrToInt(Edit1->Text);
		StringGrid1->ColCount = m;
		StringGrid1->RowCount = m;
		cargarM2(StringGrid1, 0, 0, m, 1);
	}	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N202011Click(TObject *Sender)
{
	byte f, c, m = StringGrid1->RowCount;
	cargar2020_2(StringGrid1, m, m*m, f, c);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N201921Click(TObject *Sender)
{
	byte fa = 0;
	byte fb = StringGrid1->RowCount - 1;
	byte ca = 0;
	byte cb = StringGrid1->ColCount - 1;
	byte k = 1;
	cargar2019_2B(StringGrid1, fa, fb, ca, cb, k);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N202112Click(TObject *Sender)
{
	byte f, c, m = StrToInt(Edit1->Text);
	StringGrid1->ColCount = m;
	StringGrid1->RowCount = m;
	cargarM(StringGrid1, m, 0, 0, m-1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Insertarunelementoordenado1Click(TObject *Sender)
{
  Byte n = StringGrid1->ColCount;
  Cardinal x = Edit3->Text.ToInt();
  InsertOrdDesc(StringGrid1, n, x);
  StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarPrimerosElementos1Click(TObject *Sender)
{
   Byte n =StringGrid1->ColCount;
   byte pos = Edit2->Text.ToInt();
   byte cant = Edit3->Text.ToInt();
   EliminarPrimerosElementos(StringGrid1, n, pos, cant);
   StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::eliminarprimernumero1Click(TObject *Sender)
{
	 AnsiString cant = Edit2->Text;
	 EliminarPrimerNumero(cant);
	 Edit3->Text =  cant;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Deliminarprimercaracterdecadapalabra1Click(TObject *Sender)

{
  AnsiString cadena = Edit1->Text;
  DeletePrimerCaracterDeUnaPalabraV2(cadena);
  Edit2->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N202113Click(TObject *Sender)
{
	byte fa = 0;
	byte fb = StringGrid1->RowCount - 1;
	byte ca = 0;
	byte cb = StringGrid1->ColCount - 1;
	cargarFila2021_1(StringGrid1, fa, fb, ca, cb);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N202121Click(TObject *Sender)
{
	byte men,
		 may,
		 f = StringGrid1->RowCount,
		 c = StringGrid1->ColCount;
	MayorMenorFil2021_2(StringGrid1, f, c, men, may);
	ShowMessage(men);
	ShowMessage(may);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20213202211Click(TObject *Sender)
{
	byte f = StringGrid1->RowCount;
	byte c = StringGrid1->ColCount;
	cargarFila2022_1(StringGrid1,f, c);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cargarenformavector1Click(TObject *Sender)
{
  byte N = StringGrid1->RowCount;
  cargarTipoVector(StringGrid1,N*N);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20201segundaescala1Click(TObject *Sender)
{
   byte f, c, m = StringGrid1->RowCount;
   byte k = (m*(m+1))/2;
  cargar2020_1Segunda(StringGrid1,m , k, f, c );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Magico1Click(TObject *Sender)
{
	byte f, c, m = StringGrid1->RowCount;
//  Magico(StringGrid1,m,m*m,f,c);
  Magicov1(StringGrid1,m,m*m,f,c);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::cargarbordes1Click(TObject *Sender)
{
  byte fa = 0;
  byte fb = StringGrid1->RowCount - 1;
  cargarDentroToFuera(StringGrid1, fa, fb);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N202211Click(TObject *Sender)
{
  int m = StringGrid1->RowCount;
  int x = 1;
  cargar2022_1(StringGrid1, m, 0,0,x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20221B1Click(TObject *Sender)
{
	int m = StringGrid1->RowCount;
	cargarFila2022_1B(StringGrid1, m, m);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20192A1Click(TObject *Sender)
{
  byte a = Edit3->Text.ToInt();
  byte b = Edit4->Text.ToInt();
  AnsiString res = GenerarCadena2019_2A(StringGrid1, a, b);
  ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::caracol1Click(TObject *Sender)
{
	//matriz cuadrada
	byte fa = 0;
	byte fb = StringGrid1->RowCount - 1;
	byte ca = 0;
	byte cb = StringGrid1->ColCount - 1;
	byte k = 1;
	cargarCaracol(StringGrid1, fa, fb, ca, cb, k);
}
//---------------------------------------------------------------------------

