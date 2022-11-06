//---------------------------------------------------------------------------

#include <Classes.hpp>
#include "GData.cpp"
#include <math.h>
#pragma hdrstop

#include "Walking.h"
AnsiString mesto(const char &sym, const int& Case=0)
{
  IF (CASE == 0)//ГДЕ В
  {
  SWITCH (SYM)
  {
	 CASE '0': RETURN "СТЕПИ";
	 CASE '1': RETURN "ЛЕСУ";
	 CASE '2': RETURN "ГОРАХ";
	 DEFAULT : RETURN "ХРЕН ЗНАЕТ ГДЕ";
  }
  }
  IF (CASE==1)
  {
	 SWITCH (SYM)//ВИНИТЕЛЬНЫЙ
	 {
		CASE '0': RETURN "СТЕПЬ";
		CASE '1': RETURN "ЛЕС";
		CASE '2': RETURN "ГОРЫ";
		DEFAULT : RETURN "ХРЕН ЗНАЕТ ЧТО";
	 }
  }
  IF (CASE==2) //ДАТЕЛЬНЫЙ
  {
	 SWITCH (SYM)
	 {
		CASE '0': RETURN "СТЕПИ";
		CASE '1': RETURN "ЛЕСУ";
		CASE '2': RETURN "ГОРАМ";
		DEFAULT : RETURN "ХРЕН ЗНАЕТ ЧЕМУ";
	 }
  }
  RETURN "";
}

void openfile(const AnsiString &Filename)
   {
      file->LoadFromFile(Filename);
      nLandscape = file->Count-1;
      for (int i=0;i<MAXINTS;i++)
         intmaps[i] = new int[nLandscape];
      for (int i=0;i<MAXCHARS;i++)
         charmaps[i] = new char[nLandscape];
      //charmaps = new char[nLandscape];
      for (int i=0;i<MAXSTRINGS;i++)
         strmaps[i] = new AnsiString[nLandscape];

      String str;
      char del='\t';    //Yoi ?acaaeeoaeu ' '  '\t'
      int p;   //Eiaaen ?acaaeeoaey
      String word;   //Yoi ioaaeuiua neiaa
      int curr,currstr=0,currint=0,currchar=0;

      for (int i=1;i<file->Count;i++)
      {
         curr=1;
         //while ((str=input->Strings[i]).Length() == 0)
         //{
         str = file->Strings[i];
         if (str.Length() == 0)  //Ionoo? no?ieo oaaeeou, aoaoi a? iao
         {
            //ShowMessage("Oaaeyai ionoo? no?ieo ?"+IntToStr(i));
            file->Delete(i);
            i--;  continue;  //Yoi anee ionoua no?iee a eiioa aieoiaioa
         }
         //}
         while (str.Length() != 0)  //Aio oeee ioaaey?uee neiaa
         {
            if (str[1]==del) //Aey ionaeaaiey eeoieo ?acaaeeoaeae
            {
               str.Delete(1,1);
               continue;
            }
            p=str.Pos(del);
            if (p==0)
            {
               word=str;
               str="";
            }
            else
            {
               word=str.SubString(1,p-1);
               str.Delete(1,p);
            }
            //ShowMessage(word+" "+IntToStr(curr));
            switch (curr)
            {
               case 1: strmaps[TXTMAPSNAME][i-1]=word; break;
               case 2: charmaps[TXTMAPSIDENT][i-1]=word.operator [](1); break;
               case 3: strmaps[TXTMAPSWHERE][i-1]=word; break;
               case 4: strmaps[TXTMAPSDP][i-1]=word; break;
               case 5: intmaps[TXTMAPSDUR][i-1]=StrToInt(word); break;
               case 6: intmaps[TXTMAPSFATIGUE][i-1]=StrToInt(word); break;
            }
            curr++;   
         }
      }
      charmaps[TXTMAPSIDENT][file->Count-1]=0;
   }
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
