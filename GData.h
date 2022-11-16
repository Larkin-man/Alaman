//---------------------------------------------------------------------------
#ifndef GDataH
#define GDataH
#include "TableLoader.cpp"
//---------------------------------------------------------------------------
#define cletka 40

class PLAYER
{
public:
	PLAYER() {Traveling=true;}
	bool Traveling;

}extern Player;

class MAPS
{
public:
	String  *Name;
	Char		*Id;
	String  *Where;
	String  *Dp;
	int			*Duration;
	int Count;
	int Bug, Out; //Индекс неверной локации (0) и края мира (пробел)
	TableLoader File;
}extern Maps;

class DISTANCE
{
public:
	String  *Name;
	int *Min;
	int *Max;
	int Count;
	TableLoader File;
}extern Dist;

class AROUND
{
public:
	String  *Name;
	int *ID;
	String  *To;
	int Count;
	TableLoader File;
}extern Around;

class ACTIONS
{
public:
	String  *Id;
	String  *Text;
	int Count;
	TableLoader File;
}extern Action;

class ORIENTIRS
{ public:
	String  *Name;
	int *x;
	int *y;
	String  *DP;
	bool *Available;
	int *JournalPos;
	int Count;
	TableLoader File;
}extern Orientire;

class TIMING
{
public:
	String  *Text;
		int *Time;
	int Count;
	TableLoader File;
}extern Timing;

void LOADTXTS()
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
	Timing.Count = Timing.File.LoadFromFile("Data\\TIMING.TXT","si\0", &Timing.Text, &Timing.Time);
	Action.Count = Action.File.LoadFromFile("Data\\ACTIONS.TXT","ss\0", &Action.Id, &Action.Text);
	Orientire.Count = Orientire.File.LoadFromFile("Data\\ORIENTIRS.TXT","siisbi\0", &Orientire.Name, &Orientire.x, &Orientire.y, &Orientire.DP, &Orientire.Available, &Orientire.JournalPos);
}


#endif
