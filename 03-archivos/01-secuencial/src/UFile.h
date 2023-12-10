//---------------------------------------------------------------------------

#ifndef UFileH
#define UFileH
#include <System.Classes.hpp>
#include <fstream> void
/*externos*/
#include "UConjunto.h"

/*Definicion de metodos*/
//funciones
int GetCantVocales(AnsiString nameFile);
bool VerifNivel21(AnsiString nameFile);
//procesos
void Limpiar(AnsiString name);
void CrearNivel21(AnsiString nameFile, AnsiString newNameFile);
void CrearNivel21V2(AnsiString nameFile, AnsiString newNameFile);
void SearchAndReplace(
	AnsiString name,
	AnsiString search,
	AnsiString replace
);

//---------------------------------------------------------------------------
#endif
