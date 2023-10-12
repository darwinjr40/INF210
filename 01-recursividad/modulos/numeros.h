//---------------------------------------------------------------------------

#ifndef numerosH
#define numerosH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>

#include <System.Classes.hpp>
#include <Vcl.Grids.hpp>

//contreras--------------------
byte GetCantDigPares(Cardinal n);
void GetDigMayorMenor(Cardinal n, byte &may, byte &men);
AnsiString SumaOctal(Cardinal a, Cardinal b, Cardinal ac);
String SumaOctal(Cardinal a, Cardinal b);
void moverMayorFinal(Cardinal &n);
void ordenarDigitos(Cardinal &n);
void MoverMenor(int &n); //2020-1  #1
bool VerificarPrimo(Cardinal n);
bool VerificarPrimo(Cardinal n, Cardinal i);
Cardinal GetDigParesAntesPar(Cardinal n);
//dunnia-------------------------
double serie1 (int n);
unsigned int EnesimoTerm(unsigned int n);
//shirley------------------------
byte getSumPosImp(Cardinal x);
//---------------------------------------------------------------------------
#endif
