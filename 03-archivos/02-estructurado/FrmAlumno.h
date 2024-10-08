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
	TButton *ButtonNavIdxIni;
	TButton *ButtonNavIdxSig;
	TButton *ButtonNavIdxAnt;
	TButton *ButtonNavIdxFin;
	TButton *Button13;
	TComboBox *ComboBoxCreateIdx;
	TComboBox *ComboBoxOrdenarIdx;
	TComboBox *ComboBoxExportIdx;
	TButton *Button3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall GuardarClick(TObject *Sender);
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
	void __fastcall EliminarClick(TObject *Sender);
	void __fastcall ButtonNavIdxIniClick(TObject *Sender);
	void __fastcall ButtonNavIdxSigClick(TObject *Sender);
	void __fastcall ButtonNavIdxAntClick(TObject *Sender);
	void __fastcall ButtonNavIdxFinClick(TObject *Sender);
	void __fastcall createCodigoClick(TObject *Sender);
	void __fastcall onClickCreateMonthFile(TObject *Sender);
	void __fastcall onClickLoad(TObject *Sender);
	void __fastcall onClickSearchName(TObject *Sender);
	void __fastcall searchMenByIndex(TObject *Sender);
	void __fastcall searchBinaryCodeByIndex(TObject *Sender);
	void __fastcall pregunta2(TObject *Sender);
	void __fastcall ComboBoxCreateIdxChange(TObject *Sender);
	void __fastcall ComboBoxOrdenarIdxChange(TObject *Sender);
	void __fastcall ComboBoxExportIdxChange(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
	fstream *pf, *pfi;
	AnsiString nomArch, nomArchIdxCod;
	AnsiString nomArchIdxFecha;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void UpdateForm(AnsiString cod,AnsiString nom,AnsiString dir, AnsiString fecha);
	void ShowAlumno(RegAlumno r);
	void SaveAlumno(RegAlumno regNuevo);
	void CreateIndexCodigo();
	void CreateIndexFecha();
	void OrdenarIdxCodigo();
	void OrdenarIdxFecha();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
