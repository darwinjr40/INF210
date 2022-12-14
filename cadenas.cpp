//---------------------------------------------------------------------------

#pragma hdrstop

#include "cadenas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool EsVocal(char c){
	AnsiString vocales = "aeiouAEIOU???????????????????????";
	return vocales.Pos(c) > 0;
}
//Elimina primer caracter de cada palabra
void SacaraPrimeraLetra(AnsiString &x){
	if (x != "") {
	  Cardinal pos =  x.Pos(" ");
	  if (pos == 0) {
		  pos = x.Length() + 1;
	  }
	  AnsiString palabra = x.SubString(1, pos-1);
	  x.Delete(1, pos);
	  SacaraPrimeraLetra(x);
	  palabra.Delete(1, 1);
	  x = palabra + " " + x;
	}

}


bool esDigito(char z){
	return (z>='0') && (z<='9');
}


AnsiString primerNum(AnsiString x){
 String c;
 if (x == "") {
	 c = "";
 }else{
	wchar_t z = x[1];
	x.Delete(1,1);
	if (!esDigito(z)) {
//	  if (c == "")       //variable de recursion vasio
		c = primerNum(x);
	}else{
	  if ((x != "") && (esDigito(x[1]))) {
		c = AnsiString(z) + primerNum(x);
	  }else{
		c = AnsiString(z);
	  }
	}
 }
 return c;
}



Cardinal numMayor(AnsiString x){
Cardinal m;
  if (x == "") {
	m = 0;
  }else{
	  AnsiString z = primerNum(x);
	  if (z == "") {
		 m = 0;        //return 0
	  }else{
		x.Delete(1, x.Pos(z) + z.Length()-1);
		m = numMayor(x);
		if ((z.ToInt() > m))
			m = z.ToInt();
	  }
  }
  return m;
}

//retorna el numero menor de una cadena de caracteres
Cardinal numMenor(String x){
Cardinal m;
  if (x == "") {
	m = 0;
  }else{
	  String z = primerNum(x);
	  if (z == "") {
		 m = 0;
	  }else{
		x.Delete(1, x.Pos(z) + z.Length()-1);
		m = numMenor(x);
		if ((m == 0)||(z.ToInt() < m))
			m = z.ToInt();
	  }
  }
  return m;
}

void EliminarPrimerNumero(AnsiString &x){
  if (x != "") {//
	 char e = x[1];
	 x.Delete(1,1);
	 if (!esDigito(e)) {
		EliminarPrimerNumero(x);
		x = AnsiString(e) + x;
	 } else {
	   if ((x != "")&&(esDigito(x[1])))
		  EliminarPrimerNumero(x);
	 }
  }
}

String primerPal(String x){
 String c;
 if (x == "") {
	 c = "";
 }else{
	wchar_t z = x[1];
	x.Delete(1,1);
	if (z == ' ') {
	  if (c == "")       //variable de recursion vasio
		c = primerPal(x);
	}else{
	  if ((x != "") && (x[1]!= ' ')) {
		c = String(z) + primerPal(x);
	  }else{
		c = String(z);
	  }
	}
 }
 return c;
}

String palabralarga(String x){
 String salida;
 if (x == "") {
   salida = "";
 }else{
   String cad = primerPal(x);
   if(cad=="")
	 salida ="";
   else{
	 x.Delete(1,x.Pos(cad)+cad.Length()-1);
	 salida = palabralarga(x);
	 if(cad.Length() > salida.Length())
		salida= cad;
   }
 }
	return salida;
}

String Invertir(String x){
  String r;
  byte n = x.Length();
  if (n  < 2){
	r = x;
  } else {
	String aux = x.SubString(1, n/2);
	x.Delete(1, n/2);
	aux =  Invertir(aux);
	x = Invertir(x);
	r =  x + aux;
  }
  return r;
}
bool EsAbecedario(char c){
	return (c >= 'a' && c<= 'z')
		 ||(c >= 'A' && c<= 'Z');
}

//x="123hola456como789estas012"
//x="123ola456omo789stas012"
void DeletePrimerCaracterDeUnaPalabra(AnsiString &x){
  if (x != "") {
	byte n =  x.Length();
	char e = x[n];
	x.Delete(n,1);
	bool sw = (EsAbecedario(e) && x=="") ||
			  (EsAbecedario(e) && x!="" && !EsAbecedario(x[x.Length()]));
	DeletePrimerCaracterDeUnaPalabra(x);
	if (!sw)
	 x = x + AnsiString(e);
  }
}

//123ola456como789estas012
//1 es el primer caracter
//0 caracter no valido
//sw =2, 	0       0       0       1   	0
//e = 		'1'     '2'     '3'     ''
//ban =		0;      0       1         h

void DeletePrimerCaracterDeUnaPalabraV2(AnsiString &x, byte sw){
  if (x != "") {  //x.Length() > 0
	if (sw == 2)
	  sw = (EsAbecedario(x[1]))? (1) : (0);
	char e = x[1];
	x.Delete(1,1);
	if (sw == 1)
	  DeletePrimerCaracterDeUnaPalabraV2(x, 0);
	  //nada
	else {
	  byte ban = (!EsAbecedario(e) && x!="" && EsAbecedario(x[1])) ?
			 1 : 0;
	  DeletePrimerCaracterDeUnaPalabraV2(x, ban);
	  x = (AnsiString)e + x;
	}
  }
}

void DeletePrimerCaracterDeUnaPalabraV2(AnsiString &x){
  DeletePrimerCaracterDeUnaPalabraV2(x, 2);
}


void DeleteUltimoCaracterDeUnaPalabraV2(AnsiString &x, byte sw){
  if (x != "") {  //x.Length() > 0
	if (sw == 2)
	  sw = (EsAbecedario(x[1]) && x.Length()==1)? (1) : (0);
	char e = x[1];
	x.Delete(1,1);
	if (sw == 1)
	  DeleteUltimoCaracterDeUnaPalabraV2(x, 0);
	  //nada
	else {
	  byte ban = ((x!="" && EsAbecedario(x[1]) &&  x.Length()==1)
			   || (x!="" && EsAbecedario(x[1]) && x.Length()>=2) && !EsAbecedario(x[2])) ?
			 1 : 0;
	  DeleteUltimoCaracterDeUnaPalabraV2(x, ban);
	  x = (AnsiString)e + x;
	}
  }
}


void DeleteUltimoCaracterDeUnaPalabra(AnsiString &x){
  if (x != "") {  //x.Length() > 0
	char e = x[1];
	x.Delete(1,1);
	bool sw = true;
	if (EsAbecedario(e) &&
	(x!="" && !EsAbecedario(x[1]) || x==""))
	  sw = false;
	DeleteUltimoCaracterDeUnaPalabra(x);
	if (sw)
	  x = (AnsiString)e + x;
  }
}
