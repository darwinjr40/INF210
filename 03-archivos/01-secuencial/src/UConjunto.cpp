//---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjunto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*Implementar metodos*/

bool EsVocal(char x){
  AnsiString vocales = "aeiou��������AEIOU�����";
  return vocales.Pos(x) > 0;
}

bool EsLetra(char x){
  AnsiString letras = "QWERTYUIOPASDFGHJKLZXCVBNM�qwertyuiopasdfghjklzxcvbnm���������AEIOU�����";
  return letras.Pos(x) > 0;
}
bool EsSigno(char x){
  AnsiString signos = ".;";
  return signos.Pos(x) > 0;
}