//---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjunto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*Implementar metodos*/

bool EsVocal(char x){
  AnsiString vocales = "aeiouáéíóúäüöAEIOUÁÉÍÓÚ";
  return vocales.Pos(x) > 0;
}

bool EsLetra(char x){
  AnsiString letras = "QWERTYUIOPASDFGHJKLZXCVBNMÑqwertyuiopasdfghjklzxcvbnmñáéíóúäüöAEIOUÁÉÍÓÚ";
  return letras.Pos(x) > 0;
}
bool EsSigno(char x){
  AnsiString signos = ".;";
  return signos.Pos(x) > 0;
}