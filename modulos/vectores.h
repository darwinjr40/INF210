//---------------------------------------------------------------------------

#ifndef vectoresH
#define vectoresH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Grids.hpp>
void CargarRandom(TStringGrid *v,byte n,byte a,byte b);
byte elementoMayor(TStringGrid *v,byte n);
void intercambio(TStringGrid*v,byte a, byte b );
void invertir(TStringGrid*v,byte a,byte b);
bool BusBin(TStringGrid *v, byte x, byte a, byte b);
void SelectionSort(TStringGrid *v,byte n);
byte PosMayor(TStringGrid *v,byte n);
bool esVocal(char z);
byte CantVocales(String x);
void EliminarElemento( TStringGrid *V, Word &n, byte x);

void InsertOrdDesc(TStringGrid *v, byte &n, Cardinal x);
void InsertOrdAsc(TStringGrid *v, byte &n, Cardinal x);
void CargarOrd(Cardinal num, TStringGrid*v,byte &n);//2020-2 #1
void EliminarPos(TStringGrid *v, byte &n, byte p);
void EliminarPrimerosElementos(TStringGrid *v, byte &n, byte p, byte cant);//2021-1 #2
void EliminarPrimerosElementosV2(TStringGrid *v, Word &n, Word m); //2021-1 #2 == repechaje
void GenerarNumeroInvertido(TStringGrid *v, Word n, Cardinal &x);
void GenerarNumeroInvertidoV2(TStringGrid *v, byte a, byte b, Cardinal &x);//2021-1 #1 repechaje





//dunnia
AnsiString mayorPromedio(TStringGrid *v, Word i, Word n, Double &p);
bool pertenece(TStringGrid * v, int i, int n, int x);
void Interseccion(TStringGrid * a, int n,TStringGrid * b, int m, String &x);
//---------------------------------------------------------------------------
#endif
