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
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall actualizarv3(TObject *Sender);
private:	// User declarations
	fstream *pf;
	AnsiString nomArch;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    void UpdateForm(AnsiString cod,AnsiString nom,AnsiString dir, AnsiString fecha);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
