//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//--------------------------------------------------------------------
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
#include <inifiles.hpp>
#include <System.Actions.hpp>
//---------------------------------------------------------------------------
PLAYER Player;
MAPS Maps;
DISTANCE Dist;
AROUND Around;
ACTIONS Action;
ORIENTIRS Orientire;
TIMING Timing;

class TGameForm : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
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
	TRichEdit *Out;
	TListBox *ActionBox;
	TFontEdit *FontEdit;
	TMenuItem *SelectFont1;
	TSplitter *Splitter3;
	TPanel *Panel1;
	TMemo *TimeBox;
	TMenuItem *N4;
	TMenuItem *NStart;
	TListBox *StatusBox;
	TListBox *ItemsBox;
	TListBox *JournalBox;
	void __fastcall FontEditAccept(TObject *Sender);
	void __fastcall NStartClick(TObject *Sender);
	void __fastcall ActionBoxClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
			 TShiftState Shift);
	void __fastcall JournalBoxClick(TObject *Sender);
	void __fastcall StatusBoxClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TGameForm(TComponent* Owner);
	short actions;
	//enum napr {nort = -1, tut = 0, sout = 1, west=-1, east = 1} fl;
	String Ambient[4];
	TStringList *pItems;
	#include "Events.hpp"
	#include "Walking.hpp"
	time_t t;
	bool ShowOrientirs;
	int random(const int &min, const int &max)
	{
		int randohm=rand()+X+Y;
		return (min + randohm % (max+1-min));
	}
	void ActionGo(const int& xstep, const int& ystep);
	void RefreshTime();
	String MessToText(String mess);
}; //FORM
extern PACKAGE TGameForm *GameForm;
//---------------------------------------------------------------------------
#endif
