//---------------------------------------------------------------------------

#ifndef GDataH
#define GDataH
#include "TableLoader.cpp"
//---------------------------------------------------------------------------
#define cletka 40

static class PLAYER
{
public:
   PLAYER() {Traveling=true;}
   bool Traveling;

} Player;

static class MAPS
{
public:
   AnsiString  *Name;
   char        *Id;
   AnsiString  *Where;
   AnsiString  *Dp;
   int         *Duration;
   int Count;
   int Bug, Out; //Индекс неверной локации (0) и края мира (пробел)
   TableLoader File;
} Maps;

static class DISTANCE
{
public:
   AnsiString  *Name;
   int *Min;
   int *Max;
   int Count;
   TableLoader File;
} Dist;

static class AROUND
{
public:
   AnsiString  *Name;
   int *ID;
   AnsiString  *To;
   int Count;
   TableLoader File;
} Around;

static class ACTIONS
{
public:
   AnsiString  *Id;
   AnsiString  *Text;
   int Count;
   TableLoader File;
} Action;

static class ORIENTIRS
{ public:
   AnsiString  *Name;
   int *x;
   int *y;
   AnsiString  *DP;
   bool *Available;
   int *JournalPos;
   int Count;
   TableLoader File;
} Orientire;

static void LOADTXTS()
{
   Maps.Count = Maps.File.LoadFromFile("Data\\MAPS.TXT","scssi\0", &Maps.Name, &Maps.Id, &Maps.Where, &Maps.Dp, &Maps.Duration);
   Dist.Count = Dist.File.LoadFromFile("Data\\DISTANCE.TXT","sii\0", &Dist.Name, &Dist.Min, &Dist.Max);
   Around.Count = Around.File.LoadFromFile("Data\\AROUND.TXT","sis\0", &Around.Name, &Around.ID, &Around.To);
   for (int i=0; i<Maps.Count; ++i)
   {
      if (Maps.Id[i] == ' ')
         Maps.Out = i;
      if (Maps.Id[i] == '0')
         Maps.Bug = i;
   }
   Action.Count = Action.File.LoadFromFile("Data\\ACTIONS.TXT","ss\0", &Action.Id, &Action.Text);
   Orientire.Count = Orientire.File.LoadFromFile("Data\\ORIENTIRS.TXT","siisbi\0", &Orientire.Name, &Orientire.x, &Orientire.y, &Orientire.DP, &Orientire.Available, &Orientire.JournalPos);
}


#endif
