//---------------------------------------------------------------------------

#ifndef Formulario1H
#define Formulario1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <fstream> void
/*externos*/
#include "UFile.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenTextFileDialog *OpenTextFileDialog1;
	TEdit *Edit1;
	TButtonGroup *ButtonGroup1;
	TComboBox *ComboBox1;
	void __fastcall ButtonSelectClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SelectClick(TObject *Sender);
	void __fastcall LimpiarVocSigClick(TObject *Sender);
	void __fastcall crearNivel21Form(TObject *Sender);
	void __fastcall VerificarNivel21Click(TObject *Sender);
private:	// User declarations


public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
