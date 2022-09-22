//---------------------------------------------------------------------------

#pragma hdrstop

#include "numeros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//Escribir una funci�n que devuelva la cantidad de d�gitos pares que est�n inmediatamente antes de uno impar.
//Ej. CantDigPares(3827435) ==> 2
byte CantDigPares(Cardinal n){
  byte r;
  if ( n < 10 ) {
	r = 0;
  } else { //asumimos que hay mas de 2 digitos
	//n := n /10;
	r = CantDigPares(n / 10);
	byte izq = (n /10) % 10;
	byte der = (n % 10);
	if ((izq % 2 == 0) && (der % 2 == 1)) {
	  r = r + 1;
	}
  }
  return r;
}

void mayorMenor(Cardinal n, byte &may, byte &men) {
	byte a, b;
	if (n < 10) { //n = 1
		may = n;
		men = n;
	} else {
		mayorMenor(n / 10, may, men);
		if ((n % 10) > may) {
		  may = n %10;
		}
		if ((n %10) < men) {
		  men = n %10;
		}
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
MoverMenor(int &n){
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



