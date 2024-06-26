//---------------------------------------------------------------------------

#ifndef cadenasH
#define cadenasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//#include <vcl.h>
//contreras
void Invertir1(AnsiString &x);
void Invertir2(AnsiString &x);
void Invertir3(AnsiString &x);
void Invertir4(AnsiString &x);
void Invertir5(AnsiString &x);
void Invertir51(AnsiString &x);
void Invertir52(AnsiString &x, byte a, byte b);
void Invertir6(AnsiString &x);
void Invertir7(AnsiString &x);
void SacaraPrimeraLetra(AnsiString &x);
void EliminarPrimerNumero(AnsiString &x);
bool EsVocal(char c);
bool esDigito(char z);
bool EsAbecedario(char c, bool sw);
bool EsPalabra(char x);
AnsiString primerNum(AnsiString x);  //2020_2  #2
Cardinal numMenor(String x);
Cardinal numMayor(AnsiString x);
AnsiString primerPal(AnsiString x);
String palabralarga(String x);
String Invertir(String x);
AnsiString UltimaPal(AnsiString x);
byte CantVocales(AnsiString x);
void DeleteFirstWord(AnsiString &x);
//dunnia
void DeletePrimerCaracterDeUnaPalabra(AnsiString &x);
void DeletePrimerCaracterDeUnaPalabraV2(AnsiString &x, byte sw);
void DeletePrimerCaracterDeUnaPalabraV2(AnsiString &x);

void DeleteUltimoCaracterDeUnaPalabraV2(AnsiString &x, byte sw);
void DeleteUltimoCaracterDeUnaPalabra(AnsiString &x);

void EliminarVocales(AnsiString &x);
byte GetCantidadVocales(AnsiString x);
bool EsAlfaOrNumOrEsp(char z);
byte GetCantidadNotAlfaOrNumOrEsp(AnsiString x);
//-----------------------------------------------------------
#endif
