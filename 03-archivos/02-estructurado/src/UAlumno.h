//---------------------------------------------------------------------------

#ifndef UAlumnoH
#define UAlumnoH
//---------------------------------------------------------------------------
#include <vcl.h>
//#include <System.Classes.hpp>
//#include <Vcl.Controls.hpp>
//#include <Vcl.StdCtrls.hpp>
//#include <Vcl.Forms.hpp>
//#include <Vcl.Menus.hpp>


//	RegAlumno reg = RegAlumno(100, "Juan Perez", "calle 123", TFecha(10,10,1010));

struct TFecha{
	//atributos
	byte dia;
	byte mes;
	Word anio;
	// Constructor predeterminado
	TFecha() : dia(0), mes(0), anio(0) {}
	//constructor parametrizado
	TFecha(byte d, byte m, Word a): dia(d), mes(m), anio(a){}

	AnsiString ToString() {
		return IntToStr(dia) + "/" + IntToStr(mes) + "/" + IntToStr(anio);
	}
};

struct RegAlumno{
	Word cod;      // 2 bytes
	char nom[21];  // 21 bytes
	char dir[21];  // 21 bytes
	TFecha fecha;  // 4 bytes
	// Constructor  con valores predeterminado
	RegAlumno(){};
	//constructor parametrizado
	RegAlumno(Word c, AnsiString n, AnsiString d, TFecha f) : cod(c), fecha(f) {
		strcpy(nom, n.c_str());
		strcpy(dir, d.c_str());
	}

	AnsiString ToString() {
		return (AnsiString)"{\n" +
			   "cod: " + IntToStr(this->cod)+"\n"+
			   "nom: " + this->nom + "\n"+
			   "dir: " + this->dir + "\n"+
			   "fecha: " + this->fecha.ToString()+"\n"+
				"}";
	}
};

struct RegAlumnoNew{
	char mark;    //marca de borrador
	Word cod;
	char nom[36]; //cadena de 20 caracteres
	char dir[21];
	TFecha fecha;
};

#endif
