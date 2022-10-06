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
	TMenuItem *Dunnia1;
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
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
