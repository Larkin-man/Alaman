//---------------------------------------------------------------------------
   #include <Classes.hpp>
   TStringList *map;
   int X, Y; //���������� ������
   int maxX, maxY; //������ �����
   int xstep,ystep, Xor, Yor;
//---------------------------------------------------------------------------
   AnsiString where()                  f
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
//pos - �� ������� ��������� ���������� ������ ��������� �� MAPS.txt
int pos(const char &ident)
{
   for (int i=0; i<Maps.Count; ++i)
      if (Maps.Id[i] == ident)
      {
         return i;
      }
   //�� ����� �������
   //return Maps.
}
//---------------------------------------------------------------------------
   AnsiString Pos(const int &x, const int &y, const int& Case=0)
   {
      //�������� �� ����� �� ����
      if ((x < 1) || (x > maxX))
         return edgeworld[Case];
      if ((y < 1) || (y > maxY))
         return edgeworld[Case];
      //-------------------------
      char ident = map->Strings[y][x];
      int terr=Maps.Count;
      for (int i=0;i<Maps.Count;i++)
         if (Maps.Id[i] == ident)
         {
            terr=i;
            break;
         }
      if (terr == Maps.Count)
         return bugmessage[Case];
      else
         return Maps.Name[terr];
   }
//---------------------------------------------------------------------------
   int GetInt(const char &ident, int **intstore, const int &Case=0)
   {
      int terr=Maps.Count;
      for (int i=0;i<Maps.Count;i++)
         if (Maps.Id[i] == ident)
         {
            terr=i;
            break;
         }
      if (terr == Maps.Count)
         return 0;
      else
         return intstore[Case][terr];
   }
//---------------------------------------------------------------------------
   void walk(const int& xstep=0, const int& ystep=0)
   {
      time=0;
      bool first = true;
      place = map->Strings[Y][X]; //�����
      AnsiString trav;
      trav = "�� ���� �� ";
      bool walking = true;
      do
      {
         //���� �����
         if (((X + xstep) <= 0) || ((X + xstep) > maxX))
            break;
         if (((Y + ystep) <= 0) || ((Y + ystep) > maxY))
            break;
         //----------
         char next = map->Strings[Y+ystep][X+xstep];
/* ????????        if (GetInt(next, intmaps, TXTMAPSDUR) == 0)
         {
            break;
         }                                             */
         if (next != place)      //���� ���������� ������ �� ����� ��������
            if (first == true)   //� ������ ���
            {
               place = next;     //�� �����������
            }
            else  //������ � ������� ���������
            {
/*&&&&&&               if (GetInt(next,intmaps,TXTMAPSDUR) < GetInt(place,intmaps,TXTMAPSDUR))
               {
                  trav += Pos(X,Y, TXTMAPSDP);
                  walking = false;
               }
               else
                  break;      */
            }
         X+=xstep;
         Y+=ystep;
//         time+=GetInt(place, intmaps, TXTMAPSDUR);
         first = false;
      } while(walking);

      if (first == true)
      {
         trav = "�� �� ������ ���� �� ";
         trav += Pos(X+xstep,Y+ystep, TXTMAPSDP);
         Out->Text=trav;
         return;
      }
      wait(time);
      if (walking)
      {
         trav+= Pos(X,Y, TXTMAPSDP);
         trav+= ", ������ �� ��������� � ";
         if (((X + xstep) <= 0) || ((Y + ystep) <= 0))
         trav+="���� ����";
      else
         trav+= Pos(X+xstep,Y+ystep, TXTMAPSDP);
      }
      else
      {
         trav+= ", ������ �� �������� � ";
         trav+= Pos(X,Y, TXTMAPSNAME);
      }

      trav+= ".";
      ////////////////////////////////
      //������� ������� �� events.txt
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
                  AnsiString EventTemp = Events->ReadString("events","ev"+IntToStr(j+1)," ");
                  EventTemp = MessToText(EventTemp);
                  trav+=" ";
                  trav+= EventTemp;
                  break;
               }
            }
         }
      }
      ////////////////////////////////
      Out->Text=trav;
      Status->Items->Strings[0]=("����������: "+IntToStr(X)+","+IntToStr(Y)+".");
      distance = sqrt(pow(double(X-Xor)*cletka,2)+pow(double(Y-Yor)*cletka,2));
      //Status->Items[0].Text
      Status->Items->Strings[1]=("���������: "+IntToStr(distance));
      //Status->Items->
   }
//---------------------------------------------------------------------------
   void look()
   {
      AnsiString mes;
      mes ="�� ���������� ";
      //mes+= mesto(place, 0);
      mes+= Pos(X,Y, TXTMAPSWHERE);
      mes+=", ";
      for (int i=0;i<Dist.Count;i++)
      {
         if ((Dist.Min[i] <= distance) && (Dist.Max[i] > distance))
         {
            mes+=Dist.Name[i];
            break;
         }
      }
      mes+=" ";
      mes+=where();
      mes+=" �� ��������";
      mes+=", �� ������ ";
      //mes+= mesto(map->Strings[Y-1][X], 1);
      mes+= Pos(X,Y-1, TXTMAPSNAME);
      mes+=", �� ������� ";
      mes+= Pos(X+1,Y, TXTMAPSNAME);
      mes+=", �� ��� ";
      mes+= Pos(X,Y+1, TXTMAPSNAME);
      mes+=", �� ������ ";
      mes+= Pos(X-1,Y, TXTMAPSNAME);
      mes+=".";
      Out->Text=mes;
   }

//---------------------------------------------------------------------------

   void test(const char* format, int** inter)
   {
      for (unsigned int i=0;i<strlen(format);i++)
         //ShowMessage(format[i]);
      for (int i=0;i<DISTMAXINTS;i++)
         inter[i] = new int[5];
      for (int i=0;i<DISTMAXINTS;i++)
      {
         for (int j=0;j<5;j++)
            inter[i][j] = i+j+10;
      }


   }
//--------------------------------------------------------------------------- 
