//---------------------------------------------------------------------------

#pragma hdrstop

#include "UFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
/*Implementar Metodos*/

int GetCantVocales(AnsiString nameFile){
  Cardinal cv;
  char x;
  ifstream f(nameFile.c_str());
  cv = 0;
  if ( !f.fail()) {
	while ( !f.eof()) {
	  x = f.get();
	  if ( !f.eof() && EsVocal(x))
		cv++;
	}
  }
  f.close();
  return cv;
}

void Limpiar(AnsiString name){
  char x;
  AnsiString nameTmp = "temporal.tmp";
  ifstream fi(name.c_str());
  ofstream fo(nameTmp.c_str());
  if ( !fi.fail()) {
	while ( !fi.eof()) {
	  x = fi.get();
	  if ( !fi.eof() && (EsLetra(x) || EsSigno(x) || (x == 10)))
		fo.put(x);
	}
  }
  fi.close();
  fo.close();
  remove(name.c_str());
  rename(nameTmp.c_str(),name.c_str());
}
