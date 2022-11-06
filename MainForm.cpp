//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "GData.cpp"
#include "Walking.cpp"
#include "defines.h"
#include "MainForm.h"
//#include "Debug.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "WinXP"
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
   Ambient[0] = "����";
   Ambient[1] = "����";
   Ambient[2] = "����";
   Ambient[3] = "�����";
   ItemsBox->Items->Add("�������� ������");
   ItemsBox->Items->Add("�������� ���");
   JournalBox->Items->Add("�������:");
   JournalBox->Items->Add("1.��������� �� ��������");
   StatusBox->Items->Add("");
   StatusBox->Items->Add("");
   INILoad();     //*///Resurect
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::FontEditAccept(TObject *Sender)
{
   ((TMemo*)GameForm->ActiveControl)->Font=FontEdit->Dialog->Font;
   GameForm->Font=FontEdit->Dialog->Font;
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::NDebugClick(TObject *Sender)
{
   DebugForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::NStartClick(TObject *Sender)
{
   map = new TStringList;
   map->LoadFromFile("Data\\MAP04.txt");
   AnsiString start = map->Strings[0];
   int prob = start.Pos(' ');
   maxX = StrToInt(start.SubString(1,prob-1));  start.Delete(1,prob);
   prob = start.Pos(' ');
   maxY = StrToInt(start.SubString(1,prob-1));  start.Delete(1,prob);
   prob = start.Pos(' ');
   X = StrToInt(start.SubString(1,prob-1));  start.Delete(1,prob);
   Y = StrToInt(start);
   place = map->Strings[Y][X]; //�����
   SetOrientire(0);
   Out->Text = Look();
   StatusBox->Items[0].Text=("����������: "+IntToStr(X)+","+IntToStr(Y)+".");
   //Status->Lines->Add("["+IntToStr(X)+"]["+IntToStr(Y)+"].");
   Day=1;
   Hour=6;
   Minutes=0;
   actions = 3;  //*///Resurect
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::ActionBoxClick(TObject *Sender)
{
   if (actions < 5)
   {
      if (actions == 2)
      {
         NStartClick(NULL);
         ActionBox->Items->Strings[0]="�����������";
         ActionBox->Items->Add("���� �� �����");
         ActionBox->Items->Add("���� �� ������");
         ActionBox->Items->Add("���� �� ��");
         ActionBox->Items->Add("���� �� �����");
         actions = 5;
         int ori=0;
         for (int i=0; i<Orientire.Count; ++i)
         {
            if (Orientire.Available[i] == true)
               ori++;
         }
         JournalBox->Items->Add("+��������� ("+IntToStr(ori)+")");
      }
      if (actions == 1)
      {
         LOADTXTS();
         ActionBox->Items->Strings[0]="������ ����";
         actions = 2;
      }    
      return;
   }
   switch (ActionBox->ItemIndex)
   {
      case 0: Out->Text = Look(); break;
      case 1: ActionGo(0,-1); RefreshTime(); break; //�����
      case 2: ActionGo(1,0); RefreshTime(); break;  //������
      case 3: ActionGo(0,1); RefreshTime(); break;  //��
      case 4: ActionGo(-1,0); RefreshTime(); break; //�����
   }              //*///Resurect
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   ActionBox->Clear();
   delete map;
   delete []EventPoss;
   delete []ToEvent;          //*///Resurect
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   switch (Key)
   {
      case VK_UP: ActionGo(0,-1); break; //�����
      case VK_RIGHT: ActionGo(1,0); break;  //������
      case VK_DOWN: ActionGo(0,1); break;  //��
      case VK_LEFT: ActionGo(-1,0); break; //�����
   }
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::JournalBoxClick(TObject *Sender)
{
   if (ShowOrientirs)
   {
      for (int i=0; i<Orientire.Count; ++i)
      {
      if (JournalBox->ItemIndex == Orientire.JournalPos[i])
      {
         Out->Text = "������ ��������: "+Orientire.Name[i];
         SetOrientire(i);
      }
      }
   }
   if (JournalBox->Items->Strings[JournalBox->ItemIndex].Pos("��������") > 0)
   {
      if (ShowOrientirs)
         return;
      ShowOrientirs = true;
      for (int i=0; i<Orientire.Count; ++i)
      {
         if (Orientire.Available[i] == true)
         {
            Orientire.JournalPos[i] = JournalBox->Items->Count;
            JournalBox->Items->Add(Orientire.Name[i]);
         }
      }
   }     //*///Resurect
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::RadioGroup1Click(TObject *Sender)
{
   Player.Traveling = RadioGroup1->ItemIndex;  //*///Resurect
}
//---------------------------------------------------------------------------


