#ifndef TimingPackH
#define TimingPackH
int Hour, minutes, Day;

void wait(const int &duration=0, const int &hours=0, const int &days=0)
   {
      minutes += duration;
      minutes += (hours*60);
      Day += days;
      if (minutes >= 60)
      {
         Hour += (minutes / 60);
         minutes %= 60;

         if (Hour >= 24)
         {
            Day += (Hour / 24);
            Hour %= 24;
         }
         Daytime = Daily(Hour / 6);
      }
      Memo1->Clear();
      Memo1->Lines->Add("День "+IntToStr(Day));
      if (minutes < 10)
         Memo1->Lines->Add("Время "+IntToStr(Hour)+":0"+IntToStr(minutes));
      else
         Memo1->Lines->Add("Время "+IntToStr(Hour)+":"+IntToStr(minutes));
      Memo1->Lines->Add(Ambient[Daytime]);
   }

#endif
