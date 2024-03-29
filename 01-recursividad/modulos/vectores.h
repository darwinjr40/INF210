//---------------------------------------------------------------------------

#ifndef vectoresH
#define vectoresH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Grids.hpp>
void CargarRandom(TStringGrid *v,byte n,byte a,byte b);
byte getSumV01(TStringGrid *v, byte n);
Cardinal getSumV02(TStringGrid *v, byte a, byte b);
byte elementoMayor(TStringGrid *v,byte n);
void intercambio(TStringGrid*v,byte a, byte b );
void invertir(TStringGrid*v,byte a,byte b);
bool BusBin(TStringGrid *v, byte x, byte a, byte b);
void SelectionSort(TStringGrid *v,byte n);
byte PosMayor(TStringGrid *v,byte n);
void BubbleSort(TStringGrid *v,byte n);
void Burbujear(TStringGrid *v,byte n);
bool esVocal(char z);
void EliminarElemento( TStringGrid *V, Word &n, byte x);

void InsertOrdDesc(TStringGrid *v, byte &n, Cardinal x);
void InsertOrdAsc(TStringGrid *v, byte &n, Cardinal x);
void CargarOrd(Cardinal num, TStringGrid*v,byte &n);//2020-2 #1
void EliminarPos(TStringGrid *v, byte &n, byte p);
void EliminarPrimerosElementos(TStringGrid *v, byte &n, byte p, byte cant);//2021-1 #2
void EliminarPrimerosElementosV2(TStringGrid *v, Word &n, Word m); //2021-1 #2 == repechaje
void GenerarNumeroInvertido(TStringGrid *v, Word n, Cardinal &x);
void GenerarNumeroInvertidoV2(TStringGrid *v, byte a, byte b, Cardinal &x);//2021-1 #1 repechaje
AnsiString GenerarCadena2019_2A(TStringGrid *v, byte a, byte b);
void cargar2022_2A(Cardinal num, TStringGrid *v, byte &n);
void CargarFibonacci(TStringGrid *v, byte a, byte b);
void CargarFibonacci(TStringGrid *v, byte n);
void CargarFibonacciV2(TStringGrid *v, byte &n, byte x);
void CargarPalabras(TStringGrid *v, byte &n, AnsiString x);
void CargarPalabrasV2(TStringGrid *v, byte &n, AnsiString x);
void CargarToDigitosRep(TStringGrid *v, byte &n, Cardinal x);
void CargarDigitosDeNumero(TStringGrid *v, byte &n, Cardinal x);
void Cargar2LetrasPalabras(TStringGrid *v, byte &n, AnsiString x);

//dunnia
AnsiString mayorPromedio(TStringGrid *v, Word i, Word n, Double &p);
bool pertenece(TStringGrid * v, int i, int n, int x);
bool pertenece(TStringGrid * v, int n, int x);
void Interseccion(TStringGrid * a, int n,TStringGrid * b, int m, String &x);
void MergeSort(int *Vec,unsigned int bajo,unsigned int alto,unsigned int n);
void Mezcla(int *Vec,unsigned int bajo, unsigned int centro,unsigned int alto,unsigned int n);

void exam2022_2(TStringGrid * v, unsigned int n, unsigned int &a );

//shirley


//---------------------------------------------------------------------------
#endif
