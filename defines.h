#ifndef COSN_H
#define COSN_H
//----------------

//---MAPS.TXT-----
//string`s
#define TXTMAPSNAME 0
#define TXTMAPSWHERE 1
#define TXTMAPSDP 2
//int`s
#define TXTMAPSDUR 0
//#define TXTMAPSFATIGUE 1
//char`s
#define TXTMAPSIDENT 0
//--MAX---
#define MAXINTS 1
#define MAXSTRINGS 3
#define MAXCHARS 1
//----------------------
//---distance.txt-----
//string`s
#define TXTDISTCAP 0
//int`s
#define TXTDISTMIN 0
#define TXTDISTMAX 1
//---MAX---------------
#define DISTMAXINTS 2
#define DISTMAXSTRINGS 1
//----------------------
//---around.txt-----
//string`s
#define TXTAROUNDBASE 0
#define TXTAROUNDTO 1
//---MAX---------------
#define AROUNDMAXSTRINGS 2

//FULL
const int ALLSTRINGS = MAXSTRINGS + DISTMAXINTS + AROUNDMAXSTRINGS;
const int ALLINTS = MAXINTS + DISTMAXINTS;
//----------------------
//----END------

#endif



