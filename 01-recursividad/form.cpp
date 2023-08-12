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
  AnsiString cad = Edit9->Text;
//DeleteUltimoCaracterDeUnaPalabraV2(cad, 2);
  DeletePrimerCaracterDeUnaPalabra(cad);
  Edit10->Text = cad;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::prueba1Click(TObject *Sender)
{
	char x = Edit9->Text[1];        //ASCII     AnsiString
	wchar_t y = Edit9->Text[1];     //UNICODE   String

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
  Edit10->Text = primerNum(Edit9->Text);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Numeromayor1Click(TObject *Sender)
{
	String cad = Edit9->Text;
  Edit10->Text =   numMayor(cad);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 StringGridVector1->ColCount = Edit5->Text.ToInt();
	 StringGridVector1->RowCount = 1;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::generarnumeroconunvector1Click(TObject *Sender)
{
//  entrada
	Word n = StringGrid1->ColCount;
	//proceso
	Cardinal x;
	GenerarNumeroInvertidoV2(StringGrid1, 0, n-1, x);
    //salida
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
  //entrada
  Byte n = StringGrid1->ColCount;
  Cardinal x = Edit3->Text.ToInt();
  //proceso
  InsertOrdDesc(StringGrid1, n, x);
  StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarPrimerosElementos1Click(TObject *Sender)
{
//entrada
   Byte n =StringGrid1->ColCount;
   byte pos = Edit3->Text.ToInt();
   byte cant = Edit4->Text.ToInt();
// proceso
   EliminarPrimerosElementos(StringGrid1, n, pos, cant);
   StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::eliminarprimernumero1Click(TObject *Sender)
{
	 AnsiString cant = Edit9->Text;
	 EliminarPrimerNumero(cant);
	 Edit10->Text =  cant;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Deliminarprimercaracterdecadapalabra1Click(TObject *Sender)

{
  AnsiString cadena = Edit9->Text;
  DeletePrimerCaracterDeUnaPalabraV2(cadena);
  Edit10->Text = cadena;
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
//   byte f, c, m = StringGrid1->RowCount;
//   byte k = (m*(m+1))/2;
//  cargar2020_1Segunda(StringGrid1,m , k, f, c);

  byte m = StringGrid1->RowCount;
  byte x = 0;
  cargar2020_1SegundaFil(StringGrid1, m, m, true, x);
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
//  int m = StringGrid1->RowCount;
//  int x = 1;
//  cargar2022_1(StringGrid1, m, 0,0,x);

   int fa = 0;
   int fb = StringGrid1->ColCount -1;
   cargarFila2022_1d(StringGrid1, fa, fb);
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
  byte a = Edit9->Text.ToInt();
  byte b = Edit11->Text.ToInt();
  AnsiString res = GenerarCadena2019_2A(StringGrid1, a, b);
  Edit10->Text = (res);
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

void __fastcall TForm1::N20221A1Click(TObject *Sender)
{
	byte f = StringGrid1->RowCount;
	byte c = StringGrid1->ColCount;
	cargarFila2022_2A(StringGrid1, f, c);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20222Acargarvectorconlosdigitosdeunnumero1Click(TObject *Sender){
//entrada
  Cardinal num = Edit3->Text.ToInt();
  //proceso
  byte n = 0;
  cargar2022_2A(num, StringGrid1, n);
  StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PMadentroToFuera1Click(TObject *Sender)
{
  unsigned int fa = 0;
  unsigned int fb = StringGrid1->RowCount - 1;
  cargarDentroToF(StringGrid1, fa, fb);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20223cargarVectorConSerieFibonacci1Click(TObject *Sender)
{
// byte n = StringGrid1->ColCount;
// CargarFibonacci(StringGrid1, n);
  byte dim = Edit3->Text.ToInt();
  byte n;
  CargarFibonacciV2(StringGrid1, n, dim);
  StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::cargarVectorConPalabras1Click(TObject *Sender)
{
 String cad = Edit3->Text;
 byte n;
 CargarPalabrasV2(StringGrid1, n , cad);
 StringGrid1->ColCount = n;
// ShowMessage(UltimaPal(cad));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::getmaymenClick(TObject *Sender)
{        // ctrl + /

}
//---------------------------------------------------------------------------

void __fastcall TForm1::prueba2Click(TObject *Sender)
{
  AnsiString cad = Edit9->Text;
  byte res =  GetCantidadNotAlfaOrNumOrEsp(cad);
  Edit10->Text = res;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::vectorinterseccion1Click(TObject *Sender)
{
  String cad;
  byte n = StringGrid1->ColCount;
  byte m = StringGrid2->ColCount;
  Interseccion(StringGrid1, n, StringGrid2, m, cad);
  ShowMessage(cad);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cargarDigitosrep1Click(TObject *Sender)
{
  Cardinal nro = Edit3->Text.ToInt();
  byte n;
  CargarToDigitosRep(StringGrid1, n , nro);
  StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::prueba3Click(TObject *Sender)
{
 unsigned int n = Edit3->Text.ToInt();
 unsigned int a = 1;
 exam2022_2(StringGrid1, n, a);
 StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::invertir1Click(TObject *Sender)
{
  byte a = StrToInt(Edit3->Text); //0..255
  byte b = Edit4->Text.ToInt();
  invertir(StringGrid1, a, b);
}
//---------------------------------------------------------------------------
void CargarSerie(TStringGrid *v, byte a, byte b, Word &x, Word &y, Word &z){
  byte n = b - a +1;
  if (n ==0) {  //caso base1
	 //nada
  } else if(n == 1) { //caso base2 a=0 b=0
	v->Cells[0][0] = 2;
  } else {
	CargarSerie(v, a, b-1, x, y, z);
	v->Cells[b][0] = v->Cells[b-1][0].ToInt() + x;
	x = x + y;
	y = y + z;
	if (z == 6) {
	 z = z - 2;
	}
  }
}

void CargarSerie(TStringGrid *v, byte n){
  byte a = 0;
  byte b = n-1;
  Word x = 7;
  Word y = 2;
  Word z = 6;
  CargarSerie(v, a, b, x, y ,z);
}
void __fastcall TForm1::serie1Click(TObject *Sender){
  CargarSerie(StringGridVector1, StringGridVector1->ColCount);
//  BubbleSort(StringGridVector1, StringGridVector1->ColCount);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::atriz1Click(TObject *Sender)
{
  byte fa = 0;
  byte fb = StringGrid1->RowCount - 1;
  cargarDentroToFuera1(StringGrid1, fa, fb);	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20233R1Click(TObject *Sender)
{

  byte fa = 0;
  byte fb = StringGrid1->RowCount - 1;
  byte ca = 0;
  byte cb = StringGrid1->ColCount - 1;
  cargarFil2022_3R(StringGrid1, fa, fb, ca, cb);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::cargar1Click(TObject *Sender)
{
  String cad = Edit3->Text;
  byte n;
  Cargar2LetrasPalabras(StringGrid1, n, cad);
  StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20222matriz1Click(TObject *Sender)
{
   int fa = 0;
   int fb = StringGrid1->ColCount -1;
   cargarFila2022_2(StringGrid1, fa, fb);
}
//---------------------------------------------------------------------------
//2023_1
byte GetSumaDig(Cardinal x){
  byte r;
  if (x < 10)
	r = x;
  else {
	byte d = x % 10;
	r = GetSumaDig(x/10);
	r = r + d;
  }
  return r;
}


signed char PromedioX(TStringGrid *v, byte n){
  signed char r;
  if (n == 0)
	r = 0;
  else {
	Cardinal ele = v->Cells[n-1][0].ToInt();
	signed char signo = (ele % 2 ==0)? (-1):(1);
	r = PromedioX(v, n-1);
	r = r + (signo * GetSumaDig(ele));
  }
  return r;
}
void __fastcall TForm1::promedioXElem1Click(TObject *Sender)
{
  byte n = Edit3->Text.ToInt();
  Edit2->Text = PromedioX(StringGrid1, n);
}
//---------------------------------------------------------------------------
Cardinal CargarDigitosDeNro(byte a, byte b){
  Cardinal r;
  byte dim = b -a + 1;
  if (dim == 0)
	r = 0;
  else {
	byte d = a;
	r = CargarDigitosDeNro( a+1, b);
	r = r *10 + d;
  }
  return r;
}

 //5 => '55555'
void CargarToDigitosDesc(TStringGrid *v, byte &n, Cardinal x){
  if (x == 0)
	n = 0 ;
  else {
	byte dim = x;
	CargarToDigitosDesc(v, n, x-1);
	Cardinal ele = CargarDigitosDeNro(1, dim);
	if (ele > 0) {
      v->Cells[n][0] = ele;
	  n++;
	}
  }


}
void __fastcall TForm1::cargarDigRepDesc202311Click(TObject *Sender)
{
  Cardinal x = Edit3->Text.ToInt();
  byte n;
  CargarToDigitosDesc(StringGrid1, n, x);
  StringGrid1->ColCount = n;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//metodos
void __fastcall TForm1::N20231Matriz1Click(TObject *Sender)
{
   int fa = 0;
   int fb = StringGrid1->RowCount -1;
   int ca = 0;
   int cb = StringGrid1->ColCount -1;
   byte x = 1;
   cargarFila2023_1A(StringGrid1, fa, fb, ca, cb, x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::verfiPrimoClick(TObject *Sender)
{
  Cardinal nro = StrToInt(Edit6->Text);
  bool sw = VerificarPrimo(nro);
  Edit7->Text = BoolToStr(sw, true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::getMenMayOnClick(TObject *Sender)
{
 //entrada
 Cardinal nro = StrToInt(Edit6->Text);
 //procesar
 byte mayor, menor;
 GetDigMayorMenor(nro, mayor, menor);
 // salida
 Edit7->Text = "mayor: " + IntToStr(mayor);
 Edit8->Text = "menor: " + IntToStr(menor);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::getCantDigParesClick(TObject *Sender)
{
  Cardinal nro = StrToInt(Edit6->Text);
  Edit7->Text = GetCantDigPares(nro);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::dunniaEnesi(TObject *Sender)
{
	unsigned int nro = StrToInt(Edit6->Text);
	Edit7->Text =  EnesimoTerm(nro);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::invertirClick(TObject *Sender){
  AnsiString cad;
  cad = Edit9->Text;
  Invertir2(cad);
  Edit9->Text=cad;
}
//---------------------------------------------------------------------------

