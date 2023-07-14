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
#include <iostream>


//	RegAlumno reg = RegAlumno(100, "Juan Perez", "calle 123", TFecha(10,10,1010));

struct TFecha{
	/*atributos*/
	byte dia;
	byte mes;
	Word anio;
	/*constuctores*/
	TFecha() : dia(0), mes(0), anio(0) {} 	//predeterminado
	TFecha(byte d, byte m, Word a): dia(d), mes(m), anio(a){} 	//parametrizado
	TFecha(const TFecha &f) : dia(f.dia), mes(f.mes), anio(f.anio){}	//copia
	/*ToStr*/
	AnsiString ToString() {
		return IntToStr(dia) + "/" + IntToStr(mes) + "/" + IntToStr(anio);
	}
};

struct RegAlumno{ //49 bytes

	Word cod;      // 2 bytes
	char nom[21];  // 21 bytes
	char dir[21];  // 21 bytes
	TFecha fecha;  // 4 bytes
	byte marca;    // 1 byte


	RegAlumno(): cod(0), marca(0){};

	RegAlumno(Word c, AnsiString n, AnsiString d, TFecha f) : cod(c), fecha(f), marca(0) {
		strcpy(nom, n.c_str());
		strcpy(dir, d.c_str());
	}

	RegAlumno(const RegAlumno &reg){
	  this->cod = reg.cod;
	  strcpy(this->nom, reg.nom);
	  strcpy(this->dir, reg.dir);
	  this->fecha = reg.fecha;
	  this->marca = reg.marca;
	}

	AnsiString ToString() {
		return (AnsiString)"{\n" +
			   "cod: " + IntToStr(this->cod)+"\n"+
			   "nom: " + this->nom + "\n"+
			   "dir: " + this->dir + "\n"+
			   "fecha: " + this->fecha.ToString()+"\n"+
			   "marca: " +  IntToStr(this->marca)+"\n"+
				"}";
	}
};


struct RegAlumnoV1{ //48 bytes
	Word cod;      // 2 bytes
	char nom[21];  // 21 bytes
	char dir[21];  // 21 bytes
	TFecha fecha;  // 4 bytes
};

struct RegAlumnoNew{ //62 bytes

	Word cod;      // 2 bytes
	char nom[35];  // 35 bytes
	char dir[21];  // 21 bytes
	TFecha fecha;  // 4 bytes

	RegAlumnoNew():cod(0){};
	RegAlumnoNew(Word c, AnsiString n, AnsiString d, TFecha f) : cod(c), fecha(f) {
		strncpy(nom, n.c_str(), sizeof(nom)-1);
		strncpy(dir, d.c_str(), sizeof(dir)-1);
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


struct RegIdxCod {
	Word cod;
	Cardinal pos;
};


struct  RegIdxBase {
	Cardinal pos;
	virtual void Copiar(RegAlumno &reg)=0; // Función virtual pura
	virtual AnsiString ToString()=0;

};

class  RegIdxBaseV2 {
	public:
		Cardinal pos;
		virtual AnsiString ToString(){return "sd";};
};
struct RegIdxCodV2 : RegIdxBaseV2 {
	Word cod;

};

struct RegIdxCodV1 : public  RegIdxBase {
	Word cod;

	void Copiar(RegAlumno &reg)  {
	  this->cod = reg.cod;
	};

	AnsiString ToString() {
		return (AnsiString)"{\n" +
			   "pos: " + this->pos+"\n"+
			   "cod: " +  IntToStr(this->cod) + "\n"+
				"}";
	}
};

struct RegIdxNom : public RegIdxBase {
	char nom[21];

	void Copiar(RegAlumno &reg) {
	  AnsiString regnom = reg.nom;
	  strncpy(this->nom,regnom.c_str(),21);
	};

	AnsiString ToString() {
		return (AnsiString)"{\n" +
			   "pos: " + this->pos+"\n"+
			   "nom: " +  this->nom + "\n"+
				"}";
	}
};

struct RegIdxDir : public RegIdxBase{
	char dir[21];

	void Copiar(RegAlumno &reg) {
	  AnsiString regdir = reg.nom;
	  strncpy(this->dir, regdir.c_str(),21);
	};

	AnsiString ToString() {
		return (AnsiString)"{\n" +
			   "pos: " + this->pos+"\n"+
			   "nom: " +  this->dir + "\n"+
				"}";
	}
};
struct RegIdxFecha : public RegIdxBase {
	TFecha fecha;;

	void Copiar(RegAlumno &reg) {
		this->fecha = reg.fecha;
	};

	AnsiString ToString() {
		return (AnsiString)"{\n" +
			   "pos: " + this->pos+"\n"+
			   "nom: " +  this->fecha.ToString() + "\n"+
				"}";
	}
};


//nombre de los files
struct File{
  static const AnsiString NOM_ARCH ;
  static const AnsiString NOM_ARCH_IDX_COD;
  static const AnsiString NOM_ARCH_IDX_NOM;
  static const AnsiString NOM_ARCH_IDX_DIR;
  static const AnsiString NOM_ARCH_IDX_FEC;
};
const AnsiString File::NOM_ARCH = "Alumno.dat";
const AnsiString File::NOM_ARCH_IDX_COD = "codigo.idx";
const AnsiString File::NOM_ARCH_IDX_NOM = "nombre.idx";
const AnsiString File::NOM_ARCH_IDX_DIR = "direccion.idx";
const AnsiString File::NOM_ARCH_IDX_FEC = "fecha.idx";


#endif
