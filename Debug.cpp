//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Debug.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TDebugForm *DebugForm;
//---------------------------------------------------------------------------
__fastcall TDebugForm::TDebugForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::Button1Click(TObject *Sender)
{
  // Wait(wait1->Value, Chours->Value);  *///Resurect
}
//---------------------------------------------------------------------------

void __fastcall TDebugForm::BitBtn1Click(TObject *Sender)
{
   //ShowMessage(*(GameForm->charmaps));
   //ShowMessage(AnsiString(*(GameForm->charmaps)).Length());
   //ShowMessage(GameForm->pos('s',TXTMAPSNAME));
}
//---------------------------------------------------------------------------


