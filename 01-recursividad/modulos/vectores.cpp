//---------------------------------------------------------------------------

#pragma hdrstop

#include "vectores.h"

#include "cadenas.h"
#include <iostream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CargarRandom(TStringGrid *v,byte n,byte a,byte b){
  if (n>0){
   CargarRandom(v,n-1,a,b);
   v->Cells[n-1][0]= a + Random(b-a+1);   //Random(41)-20== Rango [-20,20}
  }
 }

byte getSumV01(TStringGrid *v, byte n){
 byte s;
 if (n == 0) {
   s = 0;
 } else {
   byte x = v->Cells[n-1][0].ToInt();
   s = getSumV01(v, n-1);
   s = s + x;
 }
 return s;
}

Cardinal getSumV02(TStringGrid *v, byte a, byte b){
 Cardinal s;
 byte n = b - a + 1;
 if (n == 0) {
   s = 0;
 } else {
   Cardinal x = v->Cells[a][0].ToInt();
   s = getSumV02(v, a+1, b);
   s = s + x;
 }
 return s;
}

byte elementoMayor(TStringGrid *v,byte n){
 byte p;
 if (n==0)
   throw new Exception("Error : vector vacio");
 else if (n==1)
	p = StrToInt(v->Cells[0][0]);
 else{
	p = elementoMayor(v,n-1);
	byte m = (StrToInt(v->Cells[n-1][0]));
	if (m > p)
	  p = m;
 }
 return p;
}

void intercambio(TStringGrid*v,byte a, byte b ){
  String aux=v->Cells[a][0];
  v->Cells[a][0]=v->Cells[b][0];
  v->Cells[b][0]=aux;
}

void invertir(TStringGrid*v,byte a,byte b){
  byte n=b-a+1;
  if (n>1) {
	invertir(v,a+1,b-1);
	//	intercambio(v,a,b);
	String aux=v->Cells[a][0];
	v->Cells[a][0]=v->Cells[b][0];
	v->Cells[b][0]=aux;
  }
}


bool BusBin(TStringGrid *v, byte x, byte a, byte b){
  bool h;
  byte n = b - a + 1;
  if (n == 0) {
	h = false;
  } else if (n == 1){
	h = (x == (v->Cells[a][0].ToInt()));
  } else {
	byte c =(a+b)/2;
	if (StrToInt(v->Cells[c][0]) == x)
	  h=true;
	else if ((v->Cells[c][0].ToInt()) < x)
	  h = BusBin(v,x,c+1,b);
	else
	  h = BusBin (v,x,a,c-1);
  }
  return h;
}

void SelectionSort(TStringGrid *v,byte n){
  if (n > 1) {
	byte pm = PosMayor(v, n);
	intercambio(v, n-1, pm);
	SelectionSort(v, n-1);
  }
}

byte PosMayor(TStringGrid *v,byte n){
 byte p;
 if (n==0)
   throw new Exception("Error : vector vacio");
 else if (n==1)
	p = 0;
 else{
	p = PosMayor(v,n-1);
	Cardinal a = (v->Cells[n-1][0].ToInt());
	Cardinal b = (v->Cells[p][0].ToInt());
	if (b < a) p = n-1;
 }
 return p;
}

void BubbleSort(TStringGrid *v,byte n){
  if (n>1) {
	Burbujear(v, n);
	BubbleSort(v, n-1);
  }
}
void Burbujear(TStringGrid *v,byte n){
  if (n>1) {
	Burbujear(v, n-1);
	if ((v->Cells[n-2][0].ToInt()) > (v->Cells[n-1][0].ToInt())) {
	  intercambio(v, n-2, n-1);
	}
  }
}


bool EsVocal(char z){
	AnsiString w = "aeiouAEIOU";
	return w.Pos(z)>0;
}

void EliminarElemento( TStringGrid *V, Word &n, byte x){
 if (n > 0) {
	byte E = StrToInt(V->Cells[n-1][0]);
	n = n - 1;
	EliminarElemento(V,n,x);
	if( E != x){
	  V->Cells[n][0] = E ;
	  n = n + 1;
	}

 }
}

//v[9, 7, 6, 5, 3] (n=5,x=8) --> v[9, 8, 7, 6, 5, 3] n=6
//(n=0,x=8) v[]  -> v[8] n=1;
//v[7]  n=1   x=8  -> v[8, 7] n=2
void InsertOrdDesc(TStringGrid *v, byte &n, Cardinal x){
 if (n == 0) {     //caso base
   v->Cells[0][0] = x;
   n = 1;
 }else{
	Cardinal e = v->Cells[n-1][0].ToInt();
	if (e >= x) {   //caso base
	   v->Cells[n][0] = x;
	}else {
	   n--;
	   InsertOrdDesc(v, n, x);
	   v->Cells[n][0] = e;
	}
    n++;
 }
}

void InsertOrdAsc(TStringGrid *v, byte &n, Cardinal x){
 if (n == 0) {     //caso base
   v->Cells[0][0] = x;
   n = 1;
 }else{
	Cardinal e = v->Cells[n-1][0].ToInt();
	if (e <= x) {   //caso base
	   v->Cells[n][0] = x;
	}else {
	   n--;
	   InsertOrdAsc(v, n, x);
	   v->Cells[n][0] = e;
	}
	n++;
 }
}


void CargarOrd(Cardinal num, TStringGrid*v,byte &n){
  if(num < 10){
    v->Cells[0][0] = num;
	n = 1;
  } else {
	CargarOrd(num/10, v, n );
	InsertOrdAsc(v, n, num%10);
  }
}

void EliminarPos(TStringGrid *v, byte &n, byte p){
 if (p < n) {     //caso base
   if (p == (n-1)) {
	n = n - 1;
   } else {
	 byte e = v->Cells[n-1][0].ToInt();
	 n = n - 1;
	 EliminarPos(v, n, p);
	 v->Cells[n][0] = e;
	 n = n + 1;
   }
 }
}

void EliminarPrimerosElementos(TStringGrid *v, byte &n, byte p, byte cant){
 if (cant > 0) {     //caso base
	EliminarPos(v, n, p);
	EliminarPrimerosElementos(v, n, p, cant-1);
 }
}

void EliminarPrimerosElementosV2(TStringGrid *v, Word &n, Word m){
  if (n > 0) {
	 if (m >= n) {
	  n = 0;
	} else {
	  Word e = v->Cells[n-1][0].ToInt();
	  n--;
	  EliminarPrimerosElementosV2(v, n, m);
	  v->Cells[n][0] = e;
	  n++;
	}
  }
}

void GenerarNumeroInvertido(TStringGrid *v, Word n, Cardinal &x){
	if (n == 0) {
		x = 0;
	} else if (n == 1 ) {
		x = StrToInt(v->Cells[0][0]);
	} else{
		Word e = StrToInt(v->Cells[n-1][0]);
		GenerarNumeroInvertido(v, n-1, x);
		Word cantDig = (log10((double)x)+1);
		x = e *(pow10(cantDig))+ x  ;
	}
}
void GenerarNumeroInvertidoV2(TStringGrid *v, byte a, byte b, Cardinal &x){
  byte n = b - a + 1;
  if (n == 0)
	x = 0;
  else if(n == 1)
	x = StrToInt(v->Cells[a][0]);
   else {
	 Cardinal e = StrToInt(v->Cells[a][0]);
	 GenerarNumeroInvertidoV2(v, a+1, b, x);
	 Word cantDig = (log10((double)e)+1);
	 x = x * (pow10(cantDig)) + e;
  }
}

AnsiString GenerarCadena2019_2A(TStringGrid *v, byte a, byte b){
  byte n = b - a + 1; //n = 0
  AnsiString r;
  if (n == 0)
	r = "";
  else if(n == 1)
	r = v->Cells[b][0];
   else {
	 r = GenerarCadena2019_2A(v, a, b-1);
//	 Cardinal inv = invertir(v->Cells[b][0]);
//	 r = inv + r;
	 r = v->Cells[b][0] + r;
  }
  return r;
}
//--------------------------------------------------------

void cargar2022_2A(Cardinal num, TStringGrid *v, byte &n){
  if (num > 0){
	v->Cells[n][0] = num %10;
	n = n + 1;
	cargar2022_2A(num/10, v, n);
  }
}

//2022-3-parcial2-------------------------------------------------------
void CargarFibonacci(TStringGrid *v, byte n){
  CargarFibonacci(v, 0, n-1);
}
void CargarFibonacci(TStringGrid *v, byte a, byte b){
  byte n = b - a + 1;
  if ( n > 0) {
	if (n == 1) {
	  v->Cells[b][0] = 1;
	} else if(n == 2) {
	  v->Cells[b-1][0] = 1;
	  v->Cells[b][0] = 1;
	} else {
	  CargarFibonacci(v, a, b-1);
	  byte x = v->Cells[b-2][0].ToInt();
	  byte y = v->Cells[b-1][0].ToInt();
	  v->Cells[b][0] = x + y;
	}
  }
}

void CargarFibonacciV2(TStringGrid *v, byte &n, byte x){
  if (x == 0)
	n = 0;
  else if (x <= 2) { //x < 3  [1,2]
	 v->Cells[0][0] = 1;
	 n = 1;
	 if (x == 2) {
	   v->Cells[n][0] = 1;
	   n++;
	 }
  }else { //caso general
	CargarFibonacciV2(v, n, x-1);
	byte x = v->Cells[n-1][0].ToInt();
	byte y = v->Cells[n-2][0].ToInt();
	v->Cells[n][0] = x + y;
    n++;
  }
}
/*carga unicamente con las palabras de un string
entrada=>
x ="hola123como,est�n.esta;ma�ana##%", v[], n;
"hola11ma�ana23como,est�n.esta;ma�ana##"
salida =>
v["hola", "como", "est�n", "esta", "ma�ana"], n = 5;
	 0       1        2       3        4
	  - pos + 1
*/
void CargarPalabras(TStringGrid *v, byte &n, AnsiString x){
  if (x == "") { //caso base
	n = 0;
  } else {   //caso general
	AnsiString pal = UltimaPal(x);
	if (pal == "") { //2do caso base
	  n = 0;
	} else {
	  byte pos = x.Pos(pal);
	  x.Delete(pos, x.Length()- pos + 1);
	  CargarPalabras(v, n, x);
	  v->Cells[n][0] = pal;
	  n++;
	}
  }
}

void CargarPalabrasV2(TStringGrid *v, byte &n, AnsiString x){
  if (x == "") { //caso base
	n = 0;
  }else {   //caso general
	byte dim = x.Length();
	char e = x[dim];
	x.Delete(dim, 1);
	CargarPalabrasV2(v, n, x);
	if (EsPalabra(e)) {
	  if ( x=="" || !EsPalabra(x[x.Length()])) {
		v->Cells[n][0] = "";
		n++;
	  }
	  v->Cells[n-1][0] = v->Cells[n-1][0] + e;
	}
  }
}

void CargarDigitosDeNumero(TStringGrid *v, byte &n, Cardinal x){
  if (x > 0) {
	byte d = x % 10;
	CargarDigitosDeNumero(v, n, x/10);
	v->Cells[n][0] = d;
	n++;
  }
}

 //5 => '55555'
void CargarToDigitosRep(TStringGrid *v, byte &n, Cardinal x){
  if (x == 0) {
	n = 0 ;
  } else {          //502  [5,5,5,5,5] = []
	byte d = x % 10;
	CargarToDigitosRep(v, n, x / 10);
	Cardinal nro = d * ((pow10(d)-1) / 9); //d = 0
	CargarDigitosDeNumero(v, n, nro); //(v, n, 55555)
  }
}
//2019_3R
void Cargar2LetrasPalabras(TStringGrid *v, byte &n, AnsiString x){
  if (x == "") { //caso base
	n = 0;
  }else {   //caso general
	byte dim = x.Length();
	char e = x[dim];
	x.Delete(dim, 1);
	Cargar2LetrasPalabras(v, n, x);
	if (EsPalabra(e)) {
	  if ((x=="") || (x != "" && !EsPalabra(x[x.Length()]))) {
		v->Cells[n][0] = "";
		n++;
	  }
	  String ele = v->Cells[n-1][0];
	  if (ele.Length() < 2) {
		v->Cells[n-1][0] = v->Cells[n-1][0] + (AnsiString)e;
	  }
	}
  }
}



//dunnia--------------------------------------------------------

AnsiString mayorPromedio(TStringGrid *v, Word i, Word n, Double &p){
  AnsiString s;
  if (i >= n) {
	s =  "";
  } else {
	p = p + v->Cells[i][0].ToDouble();
	if ((i+1)==n) {
	  p = p / n;
	}
	s = mayorPromedio(v, i+1, n, p);
	if (v->Cells[i][0].ToDouble() > p) {
	 s = v->Cells[i][0] + "  " +s ;
	}
  }
  return s;
}

//void __fastcall TForm1::Numerosmayoresalpromedio1Click(TObject Sender)
//	int n = StringGrid1->ColCount;
//	Double a = 0;
//	Edit2->Text =   mayorPromedio(StringGrid1, 0, n, a);
//pertenece(vector, i=0, cantVector=3, ele)

bool pertenece(TStringGrid * v, int i, int n, int x){
  bool b;
  if (i >= n)
	b =  false;
  else {
	Cardinal elem = v->Cells[i][0].ToInt();//{columna}{fila}
	if ( elem == x) {
	  b =  true;
	} else {
	  b = pertenece(v, i+1, n, x);
	}
   }
  return b;
}

bool pertenece(TStringGrid * v, int n, int x){
  bool b;
  if (n == 0)
	b = false;
  else {
	Cardinal elem = v->Cells[n-1][0].ToInt();
	n = n - 1;
	if (elem == x)
	  b = true;
	else
	  b = pertenece(v, n, x);
  }
  return b;
}


//void __fastcall TForm1::elelementoexiste1Click(TObject *Sender)
//{
// int n = StringGrid1->ColCount;
// int x = Edit1->Text.ToInt();
// Edit2->Text = BoolToStr(pertenece(StringGrid1, 0, n, x), true);
//}

//x = '"  =>  x= "10 30"
void Interseccion(TStringGrid * a, int n,TStringGrid * b, int m, String &x){
  if (n == 0) {
	x = "";
  } else {
	 Interseccion(a,n-1, b, m, x);
	 int ele = a->Cells[n-1][0].ToInt();
	 byte posicion = x.Pos(ele);
	 bool sw =  (posicion == 0);
	if (pertenece(b, m, ele) && sw)
	  x = x + "  " + ele ;
  }
}

//void __fastcall TForm1::interseccionde2vectores1Click(TObject *Sender)
//{
//  int n = StringGrid1->ColCount;
//  int m = StringGrid2->ColCount;
//  String x;
//  Interseccion(StringGrid1, n,StringGrid2, m, x);
//  Edit3->Text =	x;
//}

//MergeSort recursivo--------------------------------------------------------

void  MergeSort(int *Vec,unsigned int bajo,unsigned int alto,unsigned int n){
if(bajo< alto){//Paso Recursivo
  unsigned int centro=(alto+bajo)/2;
  MergeSort(Vec,bajo,centro,n);
  MergeSort(Vec,centro+1,alto,n);
  Mezcla(Vec,bajo,centro+1,alto,n);
 }
}

void Mezcla(int *Vec,unsigned int bajo, unsigned int centro,unsigned int alto,unsigned int n){
	unsigned int ini_1=bajo;
	unsigned int fin_1=centro-1;
	 unsigned int ini_2= centro ;
	//fin_2=alto
	unsigned int pos= bajo;
	int *Tmp=new int[n];
	while (( ini_1 <=fin_1 )&&(ini_2<=alto)){
	  if(Vec[ini_1]<=Vec[ini_2]) Tmp[pos++]=  Vec[ini_1++];
	  else  Tmp[pos++]=  Vec[ini_2++];
	}
	while (ini_1<=fin_1)
		Tmp[pos++]=Vec[ini_1++] ;
	while (ini_2<=alto)
		Tmp[pos++]=Vec[ini_2++] ;
	 //Copiar de Tmp todos los elementos a Vec
	 for(pos=bajo;pos<=alto;pos++)
	   Vec[pos]=Tmp[pos];
}

//4, 6, 10, 26, 282
void exam2022_2(TStringGrid * v, unsigned int n,  unsigned int &a ){
  if (n == 1) {
	v->Cells[0][0] = 4;
  } else {
	exam2022_2(v, n-1, a);
	v->Cells[n-1][0] = v->Cells[n-2][0].ToInt() + (pow(2,(double)a));
	a = a *2;
  }
}
//--------------------------------------------------------
