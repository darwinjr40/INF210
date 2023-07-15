//---------------------------------------------------------------------------

#ifndef FrmAlumnoH
#define FrmAlumnoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <UAlumno.h>
#include <Vcl.Grids.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <Vcl.Menus.hpp>
#include <fstream>
#include <map>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TMaskEdit *MaskEdit1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TStringGrid *StringGrid1;
	TButton *mostrar;
	TButtonGroup *ButtonGroup1;
	TMainMenu *MainMenu1;
	TMenuItem *indices1;
	TMenuItem *codgio1;
	TButton *ButtonNavIdx;
	TButton *ButtonNavIdxSig;
	TButton *ButtonNavIdxAnt;
	TButton *ButtonFinNavIdx;
	TMenuItem *Ordenar1;
	TMenuItem *codigo1;
	TComboBox *ComboBox1;
	TMenuItem *general1;
	TMenuItem *general2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall actualizarClick(TObject *Sender);
	void __fastcall actualizarv2Click(TObject *Sender);
	void __fastcall expandirClick(TObject *Sender);
	void __fastcall actualizarv3(TObject *Sender);
	void __fastcall actualizarv4Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall showExpandirClick(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall mostrarClick(TObject *Sender);
	void __fastcall expandirFileClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall codgio1Click(TObject *Sender);
	void __fastcall ButtonNavIdxClick(TObject *Sender);
	void __fastcall ButtonNavIdxSigClick(TObject *Sender);
	void __fastcall ButtonNavIdxAntClick(TObject *Sender);
	void __fastcall ButtonFinNavIdxClick(TObject *Sender);
	void __fastcall codigo1Click(TObject *Sender);
	void __fastcall general1Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall general2Click(TObject *Sender);
private:	// User declarations
	fstream *pf, *pfIdx;
	AnsiString nomArch, nomArchIdxCod;

//	AnsiString nomArchIdx;
//	IRegIdx* regIdx;
	Registro regIdx;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void UpdateForm(AnsiString cod,AnsiString nom,AnsiString dir, AnsiString fecha);
	void ShowAlumno(RegAlumno r);
	void SaveAlumno(RegAlumno regNuevo);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
