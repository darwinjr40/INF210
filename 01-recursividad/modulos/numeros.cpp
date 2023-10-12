//---------------------------------------------------------------------------

#pragma hdrstop

#include "numeros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//Escribir una funcion que devuelva la cantidad de digitos pares que estan inmediatamente antes de uno impar.
//Ej. CantDigPares(3827435) ==> 2
byte GetCantDigPares(Cardinal n){
  byte r;
  if ( n < 10 ) {   // #caso base
	r = 0;
  } else { //asumimos que hay mas de 2 digitos  #caso general
	//n := n /10;
	r = GetCantDigPares(n / 10);
	byte izq = (n /10) % 10;
	byte der = (n % 10);
	if ((izq % 2 == 0) && (der % 2 == 1)) {
	  r = r + 1;
	}
  }
  return r;
}
//proceso que carga 2 variables por referencia{digito(mayor, menor)}
//cardinal n = 12345678
// byte may = 8;
//byte men = 1;
void GetDigMayorMenor(Cardinal n, byte &may, byte &men) {
	if (n < 10) { //n = 1
		may = n;
		men = n;
	} else {
		GetDigMayorMenor(n / 10, may, men);
		if ( (n % 10) > may ) may = n %10;
		if ( (n % 10) < men ) men = n %10;
	}
}

AnsiString SumaOctal(Cardinal a, Cardinal b, Cardinal ac){
  AnsiString res;
	if (a == 0 && b == 0) {//caso base
	  if (ac == 0) {
		res = "";
	  } else {
		res = ac;
	  }
	} else {//caso general
	  byte da = a % 10;
	  byte db = b % 10;
	  byte sm = (da +db + ac) % 8;
	  res = SumaOctal(a/10, b/10, (da +db + ac) / 8);
	  res = res + sm;
	}
	return res;
}

String SumaOctal(Cardinal a, Cardinal b){
	return SumaOctal(a, b, 0);
}

void moverMayorFinal(Cardinal &n) {
 if (n > 9) { //mas de 1 digito
	  byte d = n % 10;
	  n = n / 10;
	  moverMayorFinal(n);
	  if (d > (n%10)) {
		n=n*10+d;
	  }else{
	   d=d*10+(n%10);    //une 2 digitos
	   n=(n/10)*100+d;
	  }
 }
}

void ordenarDigitos(Cardinal &n) {
	if (n > 9) {
		moverMayorFinal(n);
		byte d = n % 10; // salvar el ultimo cuando es por referencia
		n = n / 10;
		ordenarDigitos(n);
		n = n * 10 + d;
	}
}

/*Escribir un proceso que lleve el menor de los digitos
al inicio de un numero ej--> 382731-->138273     */
void MoverMenor(int &n){
 if(n > 9){
	byte d = n % 10;
	n = n / 10;
	if((n%10) > d){
	 byte aux = d;
	 d = n % 10;
	 n = (n / 10) * 10 + (aux);
	}
	MoverMenor(n);
	n = n * 10 + d;
 }
}

//algoritmo que verifica si un numero es primo
bool VerificarPrimo(Cardinal n){ //4
	return VerificarPrimo(n, n - 1);
}


bool VerificarPrimo(Cardinal n, Cardinal i){
  bool sw;
//  if (i <= 1) {
//	sw = (i == 1 || n == 1) ? true : false;
//  } else if (n % i == 0) {
//	sw = false;
//  } else {
//	sw = VerificarPrimo(n, i-1);
//  }
  if (i == 0)
	sw =  false;
  else if (i == 1)
	sw = true;
  else if (n % i == 0)
	sw = false;
  else
	sw = VerificarPrimo(n, i-1);
  return sw;
}

Cardinal GetDigParesAntesPar(Cardinal n){
  Cardinal r;
  if ( n < 10 ) {
	r = 0;
  } else { //asumimos que hay mas de 2 digitos
	r = GetDigParesAntesPar(n / 10);
	byte izq = (n /10) % 10;
	byte der = (n % 10);
	if ((izq % 2 == 0) && (der % 2 == 1)) {
//	  r = r + 1;
		r = r * 10 + izq;
	}
  }
  return r;
}

//dunnia------------------------------------------------
//	int cantidad = Edit1->Text.ToInt(); //StrToInt(Edit1->Text)
//	Edit2->Text = serie1(cantidad);
double serie1 (int n){
 double resultado;
 if (n == 0) {
	 resultado = 0;
 } else if (n == 1) {
		ShowMessage(String((n+1)*2+1) + String(pow(2,double(n))));
		 resultado = ((n+1)*2+1) / (pow(2,double(n)));    //5/2 = 2     5.0/2 = 2.5
 } else {
		ShowMessage(String((n+1)*2+1) + String(pow(2,double(n))));
	 resultado =  ((n+1)*2+1) / (pow(2,double(n))) + serie1(n-1);
 }
  return resultado;
}


unsigned int EnesimoTerm(unsigned int n){
  unsigned int res;
  if (n == 1)
	res = 1;
  else {
	res =  EnesimoTerm(n-1);    //  res =  EnesimoTerm(n-1)*2+1;
	res = res * 2 + 1;
  }
  return res;
}

//shirley
//2023-1-----------------------------------------------------
//-sumar las posiciones impares de un numero ej:587=12;

byte getSumPosImp(Cardinal x){
  byte s;
  if (x < 10) { //caso base 1
	s = x;
  } else { //caso general
	byte d = x % 10;
	s = getSumPosImp(x/100);
	s = s + d;
  }
  return s;
}

//-----------------------------------------------------


