//---------------------------------------------------------------------------
#ifndef WalkingH
#define WalkingH
#include <math.h>
#include "GData.h"
//---------------------------------------------------------------------------
class CHE
{
	public:
	friend class TGameForm;
	TStringList *map;
	int X, Y; //Координаты игрока
	Char place;
	int maxX, maxY; //Размер карты
	int xstep,ystep;
	int OriIndex, Xor, Yor;
	int distance;
   //Тайминг
	int timer;
	enum  Daily {morning =1, day =2, evening =3, night =0} Daytime;
	int Day, Hour, Minutes ;


//---------------------------------------------------------------------------
//Wait - прибавить время (минут, часов, дней)
void Wait(const int &minutes=0, const int &hours=0, const int &days=0)
{
   timer = 0;
   Minutes += minutes;
   Minutes += (hours * 60);
   Day += days;
   if (Minutes >= 60)
   {
      Hour += (Minutes / 60);
      Minutes %= 60;

      if (Hour >= 24)
      {
         Day += (Hour / 24);
         Hour %= 24;
      }
      Daytime = Daily(Hour / 6);
   }
}
//---------------------------------------------------------------------------
UnicodeString where()
{
   int dx = (X - Xor);
   int dy = (Y - Yor);
   int sx = (dx < 0)? -1: 1;
   int sy = (dy < 0)? -1: 1;
   if (abs(dx)*4 <= abs(dy))
      sx = 0;
   if (abs(dy)*4 <= abs(dx))
      sy = 0;
   //Status->Items->Add(IntToStr(sx)+IntToStr(sy));
   return Around.To[sx+sy*3+4];
}
//---------------------------------------------------------------------------
//pos - По символу местности возвращает индекс местности из MAPS.txt
int Pos(Char &ident)
{
   for (int i=0; i<Maps.Count; ++i)
      if (Maps.Id[i] == ident)
      {
         return i;
      }
   //Не нашли локацию
   return Maps.Bug;
}
//---------------------------------------------------------------------------
//GetLoc - По координатам возвращает индекс местности
int GetLoc(const int &x, const int &y)
{
   //Проверка на выход из мира
   if ((x < 1) || (x > maxX))
      return Maps.Out;
   if ((y < 1) || (y > maxY))
      return Maps.Out;
   //-------------------------
   return Pos(map->Strings[y][x]);
}
//---------------------------------------------------------------------------
//Перемещение игрока в Х, У с ожиданием
void SetPos(const int& Xpos, const int& Ypos)
{
   X = Xpos;
   Y = Ypos;
   place = map->Strings[Y][X]; //точно
   timer += Maps.Duration[Pos(place)];
}
//---------------------------------------------------------------------------
//Проверка на выход за края
inline bool NextIsOut(const int& xstep, const int& ystep)
{
   if (((X + xstep) <= 0) || ((X + xstep) > maxX))
      return true;
   if (((Y + ystep) <= 0) || ((Y + ystep) > maxY))
      return true;
   return false;
}
//---------------------------------------------------------------------------
//Шаг в сторону
UnicodeString Step(const int& xstep, const int& ystep)
{
   timer = 0;
   place = map->Strings[Y][X]; //точно
   UnicodeString Mess;
   //Края карты
   do
   {
      if(NextIsOut(xstep, ystep))
			break;
		Char next = map->Strings[Y+ystep][X+xstep];
      if (Maps.Duration[Pos(next)] == 0){   break;    } //Нельзя идти по той местности
      if (next != place)
      {
         Mess = "Вы находитесь ";
         Mess += Maps.Where[Pos(next)];
         SetPos(X + xstep, Y + ystep);
      }

   } while(false);
   if (time == 0)
   {
      Mess = "Вы не можете идти по ";
      Mess += Maps.Dp[GetLoc(X+xstep, Y+ystep)]; //Pos(X+xstep,Y+ystep, TXTMAPSDP);
      Mess += ".";
      return Mess;
   }
   Mess += ".";
   return Mess;
}
//---------------------------------------------------------------------------
//Путешествие в одну сторону, возвращает строку описания
UnicodeString Walk(const int& xstep, const int& ystep)
{
   timer = 0;
   bool first = true;
   place = map->Strings[Y][X]; //точно
   UnicodeString trav;
   trav = "Вы идёте по ";
   bool walking = true;
   do
   {
      //Края карты
      if (((X + xstep) <= 0) || ((X + xstep) > maxX))
         break;
      if (((Y + ystep) <= 0) || ((Y + ystep) > maxY))
			break;
      //----------
		Char next = map->Strings[Y+ystep][X+xstep];
      if (Maps.Duration[Pos(next)] == 0){   break;    } //Нельзя идти по той местности                                             */
      if (next != place)      //Если собирается пройти на новый ландшавт
         if (first == true)   //В первый раз
         {
            place = next;     //То переступить
         }
         else  //Пришел к другому ландшавту
         {
            if (Maps.Duration[Pos(next)] < Maps.Duration[Pos(place)]) //   GetInt(next,intmaps,TXTMAPSDUR) < GetInt(place,intmaps,TXTMAPSDUR))
            {
               trav += Maps.Dp[GetLoc(X, Y)]; //Pos(X, Y, TXTMAPSDP);
               walking = false;
            }
               else
                  break;
         }
      SetPos(X + xstep, Y + ystep);
      first = false;
   } while(walking);

   if (first == true)
   {
      trav = "Вы не можете идти по ";
      trav += Maps.Dp[GetLoc(X+xstep, Y+ystep)]; //Pos(X+xstep,Y+ystep, TXTMAPSDP);
      return trav;
   }     
   if (walking)
   {
      trav += Maps.Dp[GetLoc(X, Y)]; //Pos(X,Y, TXTMAPSDP);
      trav += ", вскоре вы приходите к ";
      trav += Maps.Dp[GetLoc(X+xstep, Y+ystep)]; //Pos(X+xstep,Y+ystep, TXTMAPSDP);
   }
   else
   {
      trav += ", вскоре вы выходите в ";
      trav += Maps.Name[GetLoc(X, Y)];//Pos(X,Y, TXTMAPSNAME);
   }
   trav += ".";
   ////////////////////////////////
   //Вставка события из events.txt
   /*
   double xy= 1.1;
   if (Y < 10)
      xy = X + (Y/10.);
   else if (Y < 100)
      xy = X + (Y/100.);
   else if (Y < 1000)
      xy = X + (Y/1000.);
   //ShowMessage("xy="+FloatToStr(xy));
   for (int i=0;i<nEventPos;i++)
   {
      if (xy == EventPoss[i])
      {
         //ShowMessage("POSSSS"+IntToStr(i));
         int the=0;
         for (int j=0;j<nEvents;j++)
         {
            the+=ToEvent[j];
            if (i<the)
            {
               UnicodeString EventTemp = Events->ReadString("events","ev"+IntToStr(j+1)," ");
               EventTemp = MessToText(EventTemp);
               trav+=" ";
               trav+= EventTemp;
               break;
            }
         }
      }
   }  */
   ////////////////////////////////
   return trav;
}
//---------------------------------------------------------------------------
//Look - Осмотреться, возвращает текст
UnicodeString Look()
{
   UnicodeString mes;
   mes = "Вы находитесь ";
   mes += Maps.Where[GetLoc(X,Y)]; //Pos(X,Y, TXTMAPSWHERE);
   mes +=", ";
   for (int i=0; i<Dist.Count; i++)
   {
      if ((Dist.Min[i] <= distance) && (Dist.Max[i] > distance))
      {
         mes += Dist.Name[i];
         break;
      }
   }
   mes += " ";
   mes += where();
   mes += " от ";
   mes += Orientire.DP[OriIndex];
   mes += ", на севере ";
   mes += Maps.Name[GetLoc(X,Y-1)];  //Pos(X,Y-1, TXTMAPSNAME);
   mes += ", на востоке ";
   mes += Maps.Name[GetLoc(X+1,Y)]; //Pos(X+1,Y, TXTMAPSNAME);
   mes += ", на юге ";
   mes += Maps.Name[GetLoc(X,Y+1)]; //Pos(X,Y+1, TXTMAPSNAME);
   mes += ", на западе ";
   mes += Maps.Name[GetLoc(X-1,Y)]; //Pos(X-1,Y, TXTMAPSNAME);
   mes += ".";
   return mes;
}                                
//---------------------------------------------------------------------------
void SetOrientire(int index)
{
   OriIndex = index;
   Xor = Orientire.x[index];
   Yor = Orientire.y[index];
   distance = sqrt(pow(double(X-Xor)*cletka,2)+pow(double(Y-Yor)*cletka,2));
}
//---------------------------------------------------------------------------
} extern g;



#endif
