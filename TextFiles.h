//---------------------------------------------------------------------------

#ifndef TextFilesH
#define TextFilesH

#include "inifiles.hpp"
TIniFile *Events;
AnsiString sFile;
int nEvents, nEventPos;
double *EventPoss;
int *ToEvent;

void INILoad()
{
   Events = new TIniFile("Data\\events.txt");
   sFile = Events->ReadString("poss","pos1",NULL);
   nEvents = 1;
   while (Events->ValueExists("events","ev"+IntToStr(nEvents)))
   {
      nEvents++;
   }
   nEvents--;
   
   //ShowMessage(nEvents);
   int pos;
   nEventPos=0;
   for (int i = 1; i<nEvents+1; i++)
   {
      pos = 1;
      while (Events->ValueExists("poss","ev"+IntToStr(i)+"pos"+IntToStr(pos)))
      {
         nEventPos++;
         pos++;
      }
   }
   if (nEventPos != 0)
   {
      EventPoss = new double[nEventPos];
      ToEvent = new int[nEvents] ;
   }
   nEventPos=0;
   for (int i = 1; i<nEvents+1; i++)
   {  pos = 1;
      while (Events->ValueExists("poss","ev"+IntToStr(i)+"pos"+IntToStr(pos)))
      {  EventPoss[nEventPos]=Events->ReadFloat("poss","ev"+IntToStr(i)+"pos"+IntToStr(pos),-1.1 );
         nEventPos++;    pos++;
      }
      ToEvent[i-1]=pos-1;
   }
   //ShowMessage(Events->ReadFloat("poss","ev"+IntToStr(3)+"pos"+IntToStr(1),-1.2 ));

   //ShowMessage(EventPoss[1]);
}



//---------------------------------------------------------------------------
#endif
