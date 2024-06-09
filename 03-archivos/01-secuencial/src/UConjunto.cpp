//---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjunto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*Implementar metodos*/

bool EsVocal(char x){
  AnsiString vocales = "aeiouáéíóúäüöAEIOUÁÉÍÓÚÄÖÜ";
  return vocales.Pos(x) > 0;
}

bool EsLetra(char x){
  AnsiString letras = "qwertyuiopasdfghjklzxcvbnmñáéíóúäöüQWERTYUIOPASDFGHJKLZXCVBNMÑÁÉÍÓÚÄÖÜ";
  return letras.Pos(x) > 0;
}
bool EsSigno(char x){
  AnsiString signos = ".;";
  return signos.Pos(x) > 0;
}

bool EsDig(char x){
  return (x>='0' && x<='9');
}

char ToMay(char x){
  AnsiString min, may;
  byte p;
  min = "qwertyuiopasdfghjklñzxcvbnmáéióúü";
  may = "QWERTYUIOPASDFGHJKLÑZXCVBNMÁÉÍÓÚU";
  p = min.Pos(x);
  return (p==0)? (x) : (may[p]);
}

char ToNivel21(char x){//# => M
  AnsiString org  = "#hp ";
  AnsiString dest = "M@#c";
  byte p = org.Pos(x);
  return (p==0)? (x) : (dest[p]);
}

char EsNivel21(char x){
  AnsiString conj = "M@#c\n";
  byte p = conj.Pos(x);
  return (p > 0);
}
