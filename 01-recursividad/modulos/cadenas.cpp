//---------------------------------------------------------------------------

#pragma hdrstop

#include "cadenas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//invertir menos el primero
void Invertir1(AnsiString &x){
  byte n = x.Length();
  if (n > 1) {
	char aux = x[1];
	x.Delete(1, 1);
	Invertir1(x);
	x = x + aux;
  }
}

//invertir menos el ultimo
void Invertir2(AnsiString &x){
  byte n = x.Length();
  if (n > 1) {
	char aux = x[n];
	x.Delete(n, 1);
	Invertir2(x);
	x = (AnsiString)aux + x;
  }
}

//invertir menos los 2 primeros
void Invertir3(AnsiString &x){
  byte n = x.Length();
  if (n > 1) {
	AnsiString y = x.SubString(1,2);
	x.Delete(1, 2);
	Invertir3(x);
	x = x + y[2] + y[1];
  }
}

//invertir menos los 2 ultimos
void Invertir4(AnsiString &x){
  byte n = x.Length();
  if (n > 1) {
	AnsiString y = x.SubString(n-1, 2);
	x.Delete(n-1, 2);
	Invertir4(x);
	x = AnsiString(y[2]) + y[1] + x;
  }
}

//invertir menos el primero y el ultimo
void Invertir5(AnsiString &x){
  byte n = x.Length();
  if (n > 1) {
	char a = x[1];
	char b = x[n];
	x.Delete(n, 1);
	x.Delete(1, 1);
	Invertir5(x);
	x = (AnsiString)b + x + a ;
  }
}
//invertir menos el primero y el ultimo
void Invertir51(AnsiString &x){
  byte n = x.Length();
  Invertir52(x, 1, n);
}
void Invertir52(AnsiString &x, byte a, byte b){
  byte n = b - a + 1;
  if (n > 1) {
	Invertir52(x, a+1, b-1);
	char aux = x[a];
	x[a] = x[b];
    x[b] = aux;
  }
}

//invertir mitad izquierda mas corta
void Invertir6(AnsiString &x){
  byte n = x.Length();
  if (n > 1) {
	AnsiString izq = x.SubString(1, n/2);
	x.Delete(1, n/2);
	Invertir6(x);
	Invertir6(izq);
	x = x + izq;
  }
}

//invertir mitad derecha mas corta
void Invertir7(AnsiString &x){
  byte n = x.Length();
  if (n > 1) {
	AnsiString der = x.SubString(n/2+1, n - n/2);
	x.Delete(n/2+1, n - n/2);
	Invertir7(x);
	Invertir7(der);
	x =  der + x;
  }
}

bool EsVocal(char c){
	AnsiString vocales = "aeiouAEIOUáéíóúÁÉÍÓÚäëïööüÄËÏÖÜÑñ";
	return vocales.Pos(c) > 0;
}
// menos los dos ultimos
byte CantVocales(AnsiString x){
  byte c;
  byte n = x.Length();
  if (x == "") {
	c = 0;
  } else if ( n == 1) {
	c = (EsVocal(x[1]))? (1) : (0);
  } else {
	AnsiString y = x.SubString(n-1, 2);
	x.Delete(n-1, 2);
	c = CantVocales(x);
	if (EsVocal(y[1])) c++;
	if (EsVocal(y[2])) c++;
  }
  return c;
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

bool EsPalabra(char x){
	AnsiString conjunto = "abcdefghijklmnñopqrstuvwxyzáéíóú";
	byte posicion =  conjunto.Pos(x);
	return  posicion > 0;
}

AnsiString primerPal(AnsiString x){
 AnsiString c;
 if (x == "") {
	 c = "";
 }else{
	char z = x[1];
	x.Delete(1,1);
	if (EsPalabra(z)) {
	  c = AnsiString(z);
	  if ((x != "") && (EsPalabra(x[1]))) {
		c = c + primerPal(x);
	  }
	}else{
	  c = primerPal(x);
	}
 }
 return c;
}
// x = "21hola213como12"  => "como"
AnsiString UltimaPal(AnsiString x){
 AnsiString c;
 if (x == "") {
	 c = "";
 }else{
	byte p = x.Length();
	char z = x[p];
	x.Delete(p,1);
	if (EsPalabra(z)) {
	  c = AnsiString(z);
	  if ((x != "") && (EsPalabra(x[x.Length()]))) {
		c = UltimaPal(x) + c;
	  }
	}else{
	  c = UltimaPal(x);
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



void EliminarVocales(AnsiString &x){
//caso base nada
  if (x != "") { //caso general
	char aux = x[1];
	x.Delete(1,1);
	EliminarVocales(x);
	if (! EsVocal(aux)) {
	  x = (AnsiString)aux + x;
	}
  }
}

byte GetCantidadVocales(AnsiString x){
  byte res;
  if (x == "") { //caso general
	res = 0;
  }else{
	char aux = x[1];
	x.Delete(1,1);
	res = GetCantidadVocales(x);
	if (EsVocal(aux)) {
		res++;//	  res = res + 1;
	}
  }
  return res;
}

bool EsAlfaOrNumOrEsp(char z){
  AnsiString conjunto = "qwertyuiopasdfghjklzxcvbnm12345678990 ";
  byte posicionBusq = conjunto.Pos(z);
  return  posicionBusq > 0;  //true
}

byte GetCantidadNotAlfaOrNumOrEsp(AnsiString x){
  byte resp;
  if (x == "")
	resp = 0;
  else {
	char c = x[1];
	x.Delete(1,1);
	resp = GetCantidadNotAlfaOrNumOrEsp(x);
	if (! EsAlfaOrNumOrEsp(c)) {
	 resp++;  //resp := resp + 1
	}
  }

  return resp;
}
