//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "GData.h"
#include "defines.h"
#include "MainForm.h"
//#include "Debug.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGameForm *GameForm;
//---------------------------------------------------------------------------
__fastcall TGameForm::TGameForm(TComponent* Owner) : TForm(Owner)
{
   FontEdit->Dialog->Font=GameForm->Font;
	Daytime = morning;
   map = NULL;
   actions = 1;
	distance = 0;
	pItems = NULL;
   Ambient[0] = "Ночь";
   Ambient[1] = "Утро";
   Ambient[2] = "День";
	Ambient[3] = "Вечер";
	JournalBox->Items->Add("Задание");
	JournalBox->Items->Add("Добраться до водопада");
	StatusBox->Items->Add("");
	StatusBox->Items->Add("");
	EventPoss = NULL;
	ToEvent = NULL;
	INILoad();
	//for (int i = 0; i < nEventPos; ++i)
	//	ShowMessage(EventPoss[i]);
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::FontEditAccept(TObject *Sender)
{
   ((TMemo*)GameForm->ActiveControl)->Font=FontEdit->Dialog->Font;
   GameForm->Font=FontEdit->Dialog->Font;
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::NStartClick(TObject *Sender)
{
	map = new TStringList;
	map->LoadFromFile("Data\\MAP04.txt");
	String start = map->Strings[0];
   int prob = start.Pos(' ');
	maxX = StrToInt(start.SubString(1,prob-1));  start.Delete(1,prob);
	prob = start.Pos(' ');
   maxY = StrToInt(start.SubString(1,prob-1));  start.Delete(1,prob);
   prob = start.Pos(' ');
	X = StrToInt(start.SubString(1,prob-1));  start.Delete(1,prob);
   Y = StrToInt(start);
   place = map->Strings[Y][X]; //точно
   SetOrientire(0);
   Out->Text = Look();
   StatusBox->Items[0].Text=("Координаты: "+IntToStr(X)+","+IntToStr(Y)+".");
	//Status->Lines->Add("["+IntToStr(X)+"]["+IntToStr(Y)+"].");
	Day=1;
	Hour=6;
   Minutes=0;
	actions = 5;
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::ActionBoxClick(TObject *Sender)
{
	if (actions < 5)
   {
      if (actions == 2)
		{
			NStartClick(NULL);
         ActionBox->Items->Strings[0]="Осмотреться";
         ActionBox->Items->Add("Идти на север");
         ActionBox->Items->Add("Идти на восток");
         ActionBox->Items->Add("Идти на юг");
			ActionBox->Items->Add("Идти на запад");
			//ActionBox->Items->Add("Охотиться");
			NStart->Enabled = true;
         int ori=0;
         for (int i=0; i<Orientire.Count; ++i)
         {
            if (Orientire.Available[i] == true)
					ori++;
			}
			JournalBox->Items->Add("Ориентиры :"+IntToStr(ori));
      }
      if (actions == 1)
		{
			pItems = new TStringList;
			pItems->LoadFromFile("Data\\items.txt");
			if (pItems->Count >= 3)
			{
				ItemsBox->Items->Add(pItems->Strings[1]);
				ItemsBox->Items->Add(pItems->Strings[2]);
			}
			LOADTXTS();   //загружается проверено
			//for (int i=0; i<Maps.Count; ++i)
			//	ShowMessage(Maps.Name[i] + IntToStr(Maps.Duration[i]));
         ActionBox->Items->Strings[0]="Начать игру";
         actions = 2;
      }    
      return;
   }
   switch (ActionBox->ItemIndex)
   {
      case 0: Out->Text = Look(); break;
		case 1: ActionGo(0,-1); RefreshTime(); break; //Север
      case 2: ActionGo(1,0); RefreshTime(); break;  //Восток
		case 3: ActionGo(0,1); RefreshTime(); break;  //Юг
		case 4: ActionGo(-1,0); RefreshTime(); break; //Запад
		case 5:
			if (place == 'f')
				Out->Text = "Вы поймали белочку!";
			else
				Out->Text = "Вы никого не поймали.";
			Wait(30);
			RefreshTime();
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   ActionBox->Clear();
	delete map;
	IniDelete();
	delete pItems;
	//delete []EventPoss;
	//delete []ToEvent;
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   switch (Key)
   {
		case VK_UP: ActionGo(0,-1); break; //Север
      case VK_RIGHT: ActionGo(1,0); break;  //Восток
      case VK_DOWN: ActionGo(0,1); break;  //Юг
      case VK_LEFT: ActionGo(-1,0); break; //Запад
   }
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::JournalBoxClick(TObject *Sender)
{
	if (ShowOrientirs)
	{
		for (int i=0; i<Orientire.Count; ++i)
			if (JournalBox->ItemIndex == Orientire.JournalPos[i])
			{
				Out->Text = "Выбран ориентир: "+Orientire.Name[i];
				SetOrientire(i);
			}
   }
   if (JournalBox->Items->Strings[JournalBox->ItemIndex].Pos("Ориентир") > 0)
	{
		if (ShowOrientirs)
			return;
      ShowOrientirs = true;
		for (int i=0; i<Orientire.Count; ++i)
         if (Orientire.Available[i] == true)
         {
            Orientire.JournalPos[i] = JournalBox->Items->Count;
            JournalBox->Items->Add(Orientire.Name[i]);
			}
	}
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::StatusBoxClick(TObject *Sender)
{
	if (StatusBox->ItemIndex >= 2)
	{
		Player.Traveling = !Player.Traveling;
		if (Player.Traveling)
			StatusBox->Items->Strings[2] = "Идти пешком";
		else
			StatusBox->Items->Strings[2] = "Бежать";
   }
}
//---------------------------------------------------------------------------


