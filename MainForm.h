//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ExtActns.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Tabs.hpp>
#include <TabNotBk.hpp>
#include <math.h>
#include <time.h>    
#include <Grids.hpp>
#include <ValEdit.hpp>
//#include "WinXP.hpp"
#include "Walking.cpp"
//#include "WinXP.hpp"


//---------------------------------------------------------------------------

class TGameForm : public TForm
{
__published:	// IDE-managed Components
   TActionList *ActionList1;
   TFileOpen *FileOpen1;
   TFileSaveAs *FileSaveAs1;
   TFileExit *FileExit1;
   TMainMenu *MainMenu1;
   TMenuItem *Open1;
   TFileRun *FileRun1;
   TMenuItem *N1;
   TMenuItem *Open2;
   TMenuItem *SaveAs1;
   TMenuItem *Run1;
   TMenuItem *Exit1;
   TEditCut *EditCut1;
   TMenuItem *Cut1;
   TStatusBar *StatusBar1;
   TPanel *PanelStatus;
   TSplitter *Splitter2;
   TPanel *PanelLeft;
   TPanel *PanelAction;
   TSplitter *Splitter1;
   TPanel *PanelGame;
   TPageControl *PageControl1;
   TTabSheet *TabSheet1;
   TTabSheet *TabSheet2;
   TTabSheet *ListQuest;
   TImageList *ImageList1;
   TImageList *ImageList2;
   TRichEdit *Out;
   TListBox *ActionBox;
   TFontEdit *FontEdit;
   TMenuItem *SelectFont1;
   TSplitter *Splitter3;
   TMenuItem *N2;
   TMenuItem *NDebug;
   TPanel *Panel1;
   TMemo *TimeBox;
   TMenuItem *N4;
   TMenuItem *NStart;
   TListBox *StatusBox;
   TListBox *ItemsBox;
   TListBox *JournalBox;
   TRadioGroup *RadioGroup1;
   void __fastcall FontEditAccept(TObject *Sender);
   void __fastcall NDebugClick(TObject *Sender);
   void __fastcall NStartClick(TObject *Sender);
   void __fastcall ActionBoxClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
   void __fastcall JournalBoxClick(TObject *Sender);
   void __fastcall RadioGroup1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TGameForm(TComponent* Owner);
   short actions;
   //enum napr {nort = -1, tut = 0, sout = 1, west=-1, east = 1} fl;
   AnsiString Ambient[4];
   //#include "TimingPack.h"
   #include "TextFiles.h"
   time_t t;
   bool ShowOrientirs;

   int random(const int &min, const int &max)
   {
      srand((unsigned) time(&t));
     //srand(time);   //рандомизация называется. Типа зерно задаем
     int randohm=rand()+X+Y;
     return (min + randohm % (max+1-min));      //*///Resurect
   }    
//---------------------------------------------------------------------------   
//Действие - идти ...
void ActionGo(const int& xstep, const int& ystep)
{
   if (Player.Traveling)
      Out->Text = Walk(xstep, ystep);
   else
      Out->Text = Step(xstep, ystep);
   if (timer > 0)
   {
      Wait(timer);
      distance = sqrt(pow(double(X-Xor)*cletka,2)+pow(double(Y-Yor)*cletka,2));
   }             //*///Resurect
}
//---------------------------------------------------------------------------
void RefreshTime()
{                                           
   TimeBox->Clear();
   TimeBox->Lines->Add("День "+IntToStr(Day));
   if (Minutes < 10)
      TimeBox->Lines->Add("Время "+IntToStr(Hour)+":0"+IntToStr(Minutes));
   else
      TimeBox->Lines->Add("Время "+IntToStr(Hour)+":"+IntToStr(Minutes));
   TimeBox->Lines->Add(Ambient[Daytime]);
   StatusBox->Items->Strings[0]=("Координаты: "+IntToStr(X)+","+IntToStr(Y)+".");
   StatusBox->Items->Strings[1]=("Дистанция: "+IntToStr(distance));  //*///Resurect
}
//---------------------------------------------------------------------------
   AnsiString MessToText(AnsiString mess)
   {  
      while (mess.Pos('%') != 0 )
      {
         if (mess.AnsiPos("%day")!=0)
         {
            int m = mess.AnsiPos("%day");
            mess.Delete(m,4);
            mess.Insert(IntToStr(Day),m);
            continue;
         }
         if (mess.AnsiPos("%pos")!=0)
         {
            int m = mess.AnsiPos("%pos");
            mess.Delete(m,4);
            mess.Insert(Maps.Dp[GetLoc(X,Y)], m);// Pos(X,Y, TXTMAPSDP),m);
            continue;
         }
         int p = mess.Pos('%');
         mess[p]='_';
      }
      return mess;     //*///Resurect
   }
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
extern PACKAGE TGameForm *GameForm;
//---------------------------------------------------------------------------
#endif
