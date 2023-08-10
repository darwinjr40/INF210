//---------------------------------------------------------------------------

#ifndef formH
#define formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//--------------------------------------------------
#include "cadenas.h"
#include "vectores.h"
#include "numeros.h"
#include "matriz.h"
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ButtonGroup.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TMainMenu *MainMenu1;
	TMenuItem *cadenas1;
	TMenuItem *eliminarprimeraletradecadapalabra1;
	TMenuItem *prueba1;
	TMenuItem *PRIMERNumero1;
	TMenuItem *Numeromayor1;
	TStringGrid *StringGrid1;
	TButton *Button1;
	TMenuItem *Vector1;
	TMenuItem *eliminarelementosdeunapos1;
	TMenuItem *generarnumeroconunvector1;
	TButton *Button2;
	TButton *Button3;
	TMenuItem *matriz1;
	TMenuItem *N201931;
	TMenuItem *N202021;
	TMenuItem *N202111;
	TMenuItem *N202011;
	TMenuItem *N201921;
	TMenuItem *N202112;
	TMenuItem *Vector2;
	TMenuItem *Insertarunelementoordenado1;
	TMenuItem *EliminarPrimerosElementos1;
	TMenuItem *eliminarprimernumero1;
	TMenuItem *Deliminarprimercaracterdecadapalabra1;
	TEdit *Edit4;
	TMenuItem *N202113;
	TMenuItem *N202121;
	TMenuItem *N20213202211;
	TMenuItem *cargarenformavector1;
	TMenuItem *N20201segundaescala1;
	TMenuItem *Magico1;
	TMenuItem *cargarbordes1;
	TMenuItem *N202211;
	TMenuItem *N20221B1;
	TMenuItem *N20192A1;
	TMenuItem *caracol1;
	TMenuItem *N20221A1;
	TMenuItem *N20222Acargarvectorconlosdigitosdeunnumero1;
	TMenuItem *PMadentroToFuera1;
	TMenuItem *N20223cargarVectorConSerieFibonacci1;
	TMenuItem *cargarVectorConPalabras1;
	TMenuItem *prueba2;
	TMenuItem *vectorinterseccion1;
	TStringGrid *StringGrid2;
	TMenuItem *cargarDigitosrep1;
	TMenuItem *prueba3;
	TMenuItem *invertir1;
	TMenuItem *serie1;
	TMenuItem *atriz1;
	TMenuItem *N20233R1;
	TMenuItem *cargar1;
	TMenuItem *N20222matriz1;
	TMenuItem *promedioXElem1;
	TMenuItem *cargarDigRepDesc202311;
	TMenuItem *N20231Matriz1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TButtonGroup *ButtonGroup1;
	TStringGrid *StringGridVector1;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	void __fastcall eliminarprimeraletradecadapalabra1Click(TObject *Sender);
	void __fastcall prueba1Click(TObject *Sender);
	void __fastcall PRIMERNumero1Click(TObject *Sender);
	void __fastcall Numeromayor1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall generarnumeroconunvector1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall N201931Click(TObject *Sender);
	void __fastcall N202021Click(TObject *Sender);
	void __fastcall N202111Click(TObject *Sender);
	void __fastcall N202011Click(TObject *Sender);
	void __fastcall N201921Click(TObject *Sender);
	void __fastcall N202112Click(TObject *Sender);
	void __fastcall Insertarunelementoordenado1Click(TObject *Sender);
	void __fastcall EliminarPrimerosElementos1Click(TObject *Sender);
	void __fastcall eliminarprimernumero1Click(TObject *Sender);
	void __fastcall Deliminarprimercaracterdecadapalabra1Click(TObject *Sender);
	void __fastcall N202113Click(TObject *Sender);
	void __fastcall N202121Click(TObject *Sender);
	void __fastcall N20213202211Click(TObject *Sender);
	void __fastcall cargarenformavector1Click(TObject *Sender);
	void __fastcall N20201segundaescala1Click(TObject *Sender);
	void __fastcall Magico1Click(TObject *Sender);
	void __fastcall cargarbordes1Click(TObject *Sender);
	void __fastcall N202211Click(TObject *Sender);
	void __fastcall N20221B1Click(TObject *Sender);
	void __fastcall N20192A1Click(TObject *Sender);
	void __fastcall caracol1Click(TObject *Sender);
	void __fastcall N20221A1Click(TObject *Sender);
	void __fastcall N20222Acargarvectorconlosdigitosdeunnumero1Click(TObject *Sender);
	void __fastcall PMadentroToFuera1Click(TObject *Sender);
	void __fastcall N20223cargarVectorConSerieFibonacci1Click(TObject *Sender);
	void __fastcall cargarVectorConPalabras1Click(TObject *Sender);
	void __fastcall getmaymenClick(TObject *Sender);
	void __fastcall prueba2Click(TObject *Sender);
	void __fastcall vectorinterseccion1Click(TObject *Sender);
	void __fastcall cargarDigitosrep1Click(TObject *Sender);
	void __fastcall prueba3Click(TObject *Sender);
	void __fastcall invertir1Click(TObject *Sender);
	void __fastcall serie1Click(TObject *Sender);
	void __fastcall atriz1Click(TObject *Sender);
	void __fastcall N20233R1Click(TObject *Sender);
	void __fastcall cargar1Click(TObject *Sender);
	void __fastcall N20222matriz1Click(TObject *Sender);
	void __fastcall promedioXElem1Click(TObject *Sender);
	void __fastcall cargarDigRepDesc202311Click(TObject *Sender);
	void __fastcall N20231Matriz1Click(TObject *Sender);
	void __fastcall verfiPrimoClick(TObject *Sender);
	void __fastcall getMenMayOnClick(TObject *Sender);
	void __fastcall getCantDigParesClick(TObject *Sender);
	void __fastcall dunniaEnesi(TObject *Sender);
	void __fastcall Vector1Click(TObject *Sender);
	void __fastcall eliminarelementosdeunapos1Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
