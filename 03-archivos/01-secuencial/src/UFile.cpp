//---------------------------------------------------------------------------

#pragma hdrstop

#include "UFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
/*Implementar Metodos*/

AnsiString ToStr(AnsiString nameFile){
  char x;
  AnsiString r = "";
  ifstream f(nameFile.c_str());
  if ( !f.fail()) {
	x = f.get();
	while ( !f.eof()) {
//	  if(x != '\n'){ // x != 10
		r = r+x;
//	  }
	  x = f.get();
	}
  }
  f.close();
  return r;
}

int GetCantVocales(AnsiString nameFile){
  Cardinal cv;
  char x;
  ifstream f(nameFile.c_str()); //n : natural; n:=Natural.create();
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

//ios::out -> escritura
//ios::in -> lectura
//ios::trunc->(no existe se creaFile)or(existe se sobreEscribe File)
void CrearNivel21(AnsiString nameFile, AnsiString newNameFile){
  char img; char z='@';char w='M';char k='#';char o='c'; char s='\n';
  fstream *pf = new fstream(nameFile.c_str(),ios::in);
  fstream pg(newNameFile.c_str(),ios::out|ios::trunc|ios::in);
  Integer f = pg.tellp();  //get pos del puntero
  if ((!pf->fail())&&(!pg.fail())) {
	while (!pf->eof()){
	  img=pf->get();
	  switch (img){
		case '#':pg.write((char *)&w,1);break;
		case 'h':pg.write((char *)&z,1);break;
		case 'p':pg.write((char *)&k,1);break;
		case ' ':pg.write((char *)&o,1);break;
		case '\n':pg.write((char *)&s,1);break;
	  }
	  f = pg.tellp();
	}
  }
  delete pf;  //<=> delete(pf);
}

void CrearNivel21V2(AnsiString nameFile, AnsiString newNameFile){
  char car;
  fstream *pf = new fstream(nameFile.c_str(),ios::in);
  fstream pg(newNameFile.c_str(),ios::out|ios::trunc|ios::in);
  if (!pf->fail() && !pg.fail()) {
	while (!pf->eof()){
	  car=pf->get();
	  if (!pf->eof()) {
		car = ToNivel21(car);
		pg << car; //write
	  }
	}
  }
  delete pf;  //<=> delete(pf);
  pg.close();
}

void CreateNumbersByLine(AnsiString nameFile, AnsiString newNameFile){
  char x, ant;
  Word c;
  fstream pf(nameFile.c_str(), ios::in);
  fstream pg(newNameFile.c_str(), ios::trunc | ios::out);
  if (!pf.fail() && !pg.fail()) {	 
	c = 0;
	while ( !pf.eof() ){
	  x = pf.get();	   
	  ant = x;
	  while (!pf.eof() && EsDig(x)) {
		x = pf.get();
	  }
	  if(ant != x)c++;
	  if(x == '\n'){										 
		pg << c;
		pg << '\n';
		c = 0;
	  }	  
	}
  }
  pf.close();
  pg.close();
}

bool VerifNivel21(AnsiString nameFile){
  char car;
  bool sw = true;
  fstream pg(nameFile.c_str(),ios::in);
  if(!pg.fail()){
	while ( !pg.eof() && sw ){
	  car=pg.get();
//	  if ( !pg.eof() && !EsNivel21(car) && car!=10)
	  if ( !pg.eof() && !EsNivel21(car))
		  sw = false;
	}
  }
  pg.flush();
  pg.close();
  return sw;
}

void SearchAndReplace(
	AnsiString name,
	AnsiString search,
	AnsiString replace
){
  char x;
  byte i, n = search.Length();
  AnsiString s;
  AnsiString nameTmp = "temporal.tmp";
  ifstream fi(name.c_str());
  ofstream fo(nameTmp.c_str());
  if ( !fi.fail()) {
	while ( !fi.eof()) {
	  x = fi.get();
	  if (x == search[1]) {
		 s = "";
		 i=1;
		 while(i<=n && !fi.eof() && x==search[i]){
		   s = s + x;
		   x = fi.get();
		   i++;
		 }
//		 encontro = true
//		 while(i<=n && !fi.eof()&& encontro){
//		   if(x!=search[i]){
//			 encontro = false;
//		   } else {
//			 s = s + x;
//			 x = fi.get();
//			 i++;
//		   }
//		 }
		 if (i>n) { //se encontro es identico
		   fo << (replace+x);
		 } else { //no se encontro
		   fo << (s+x);
		 }
	  } else {
		if(!fi.eof()) fo.put(x);
	  }
	}
  }
  fi.close();
  fo.close();
  remove(name.c_str());
  rename(nameTmp.c_str(),name.c_str());
}
