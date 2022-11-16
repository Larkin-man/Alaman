//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "GData.h"
#include "defines.h"
#include "MainForm.h"

//---------------------------------------------------------------------------
//#pragma package(smart_init)
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
	Ambient[0] = "����";
	Ambient[1] = "����";
	Ambient[2] = "����";
	Ambient[3] = "�����";
	JournalBox->Items->Add("�������");
	JournalBox->Items->Add("��������� �� ��������");
	StatusBox->Items->Add("");
	StatusBox->Items->Add("");
	EventPoss = NULL;
	ToEvent = NULL;
	INILoad();
	//for (int i = 0; i < nEventPos; ++i)
	//	ShowMessage(EventPoss[i]);
	//srand(time);	//������������ ����������. ���� ����� ������
	srand((unsigned) time(&t));
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
	place = map->Strings[Y][X]; //�����
	SetOrientire(0);
	Out->Text = Look();
	StatusBox->Items[0].Text=("����������: "+IntToStr(X)+","+IntToStr(Y)+".");
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
			ActionBox->Items->Strings[0]="�����������";
			ActionBox->Items->Add("���� �� �����");
			ActionBox->Items->Add("���� �� ������");
			ActionBox->Items->Add("���� �� ��");
			ActionBox->Items->Add("���� �� �����");
			//ActionBox->Items->Add("���������");
			NStart->Enabled = true;
			int ori=0;
			for (int i=0; i<Orientire.Count; ++i)
			{
				if (Orientire.Available[i] == true)
					ori++;
			}
			JournalBox->Items->Add("��������� :"+IntToStr(ori));
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
			LOADTXTS();	//����������� ���������
			//for (int i=0; i<Maps.Count; ++i)
			//	ShowMessage(Maps.Name[i] + IntToStr(Maps.Duration[i]));
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
		case 5:
			if (place == 'f')
				Out->Text = "�� ������� �������!";
			else
				Out->Text = "�� ������ �� �������.";
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
			if (JournalBox->ItemIndex == Orientire.JournalPos[i])
			{
				Out->Text = "������ ��������: "+Orientire.Name[i];
				SetOrientire(i);
			}
	}
	if (JournalBox->Items->Strings[JournalBox->ItemIndex].Pos("��������") > 0)
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
			StatusBox->Items->Strings[2] = "���� ������";
		else
			StatusBox->Items->Strings[2] = "������";
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//�������� - ���� ...
void TGameForm::ActionGo(const int& xstep, const int& ystep)
{
	if (Player.Traveling)
		Out->Text = Walk(xstep, ystep);
	else
		Out->Text = Step(xstep, ystep);
	if (timer > 0)
	{
		//Out->Lines->Add(timer);
		Wait(timer);
		distance = sqrt(pow(double(X-Xor)*cletka,2)+pow(double(Y-Yor)*cletka,2));
	}
}
//---------------------------------------------------------------------------
void TGameForm::RefreshTime()
{
	TimeBox->Clear();
	TimeBox->Lines->Add("���� "+IntToStr(Day));
	if (Minutes < 10)
		TimeBox->Lines->Add("����� "+IntToStr(Hour)+":0"+IntToStr(Minutes));
	else
		TimeBox->Lines->Add("����� "+IntToStr(Hour)+":"+IntToStr(Minutes));
	TimeBox->Lines->Add(Ambient[Daytime]);
	StatusBox->Items->Strings[0]=("����������: "+IntToStr(X)+","+IntToStr(Y)+".");
	StatusBox->Items->Strings[1]=("���������: "+IntToStr(distance));
	if ((Day > 5)&&(ActionBox->Items->Count == 5))
	{
		ActionBox->Items->Add("���������");
		StatusBox->Items->Add("���� ������");
	}
}
//---------------------------------------------------------------------------
String TGameForm::MessToText(String mess)
{
	while (mess.Pos('%') != 0 )
	{
		if (mess.Pos("%day")!=0)
		{
			int m = mess.Pos("%day");
			mess.Delete(m,4);
			mess.Insert(IntToStr(Day),m);
			continue;
		}
		if (mess.Pos("%pos")!=0)
		{
			int m = mess.Pos("%pos");
			mess.Delete(m,4);
			mess.Insert(Maps.Dp[GetLoc(X,Y)], m);// Pos(X,Y, TXTMAPSDP),m);
			continue;
		}
		int p = mess.Pos('%');
		mess[p]='_';
	}
	return mess;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


