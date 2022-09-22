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
byte CantDigPares(Cardinal n);
void mayorMenor(Cardinal n, byte &may, byte &men);
AnsiString SumaOctal(Cardinal a, Cardinal b, Cardinal ac);
String SumaOctal(Cardinal a, Cardinal b);
void moverMayorFinal(Cardinal &n);
void ordenarDigitos(Cardinal &n);
MoverMenor(int &n); //2020-1  #1
//dunnia-------------------------
double serie1 (int n);
//---------------------------------------------------------------------------
#endif
