#ifndef LoadingPackH
#define LoadingPackH
TStringList *file;

int IncludeFile(const AnsiString &Filename, const char* format,
      int** &masint, char** &maschar, AnsiString** &masstr)
   {
      TStringList *file = new TStringList;
      try {
         file->LoadFromFile(Filename);     }
      catch (...)
      {
         ShowMessage("Cannot open "+Filename);
         return 0;
      }
      //----vars-------------
      int maxints=0, maxchars=0, maxstrings=0;
      int nCount = file->Count-1;
      //---------------------
      //Разбор строки формата
      for (unsigned int i=0;i<strlen(format);i++)
         switch (format[i])
         {
            case 'i': maxints++; break;
            case 'c': maxchars++; break;
            case 's': maxstrings++; break;
            //default: ShowMessage("What :"+format[i]);
         }
      //----------------------
      //Создание массивов по кооличеству строк в файле
      if (maxints > 0)
      {
         masint = new int* [maxints];
         for (int i=0;i<maxints;i++)
            masint[i] = new int[nCount];
      }
      if (maxchars > 0)
      {
         maschar = new char* [maxchars];
         for (int i=0;i<maxchars;i++)
            maschar[i] = new char[nCount];
      }
      if (maxstrings > 0)
      {
         masstr = new AnsiString* [maxstrings];
         for (int i=0;i<maxstrings;i++)
            masstr[i] = new AnsiString[nCount];
      }
      //-----------------------------------------------
      //Началось считывание файл и разбор по словам
      String str;
      char del='\t';    //Это разделитель ' '  '\t'
      int p;   //Индекс разделителя
      String word;   //Это отдельные слова
      int curr=0,currstr=0,currint=0,currchar=0;
      for (int i=1;i<file->Count;i++)
      {
         curr=0;currstr=0;currint=0;currchar=0;
         str = file->Strings[i];
         if (str == "[end]")
            break;
         if (str.Length() == 0)  //Пустую строку удалить, будто её нет
         {  //ShowMessage("Удаляем пустую строку №"+IntToStr(i));
            file->Delete(i);
            i--;  continue;  //Это если пустые строки в конце документа
         }
         while (str.Length() != 0)  //Вот цикл отделяющий слова
         {  if (str[1]==del) //Для отсеивания лишних разделителей
               {  str.Delete(1,1);  continue;   }
            p=str.Pos(del);
            if (p==0)
               {  word=str;   str="";  }
            else
               {  word=str.SubString(1,p-1);   str.Delete(1,p);  }
            //Слово получено
            switch (format[curr])
            {
               case 'i' :  masint[currint][i-1]=StrToInt(word); currint++; break;
               case 'c' :  maschar[currchar][i-1]=word.operator [](1); currchar++; break;
               case 's' :  masstr[currstr][i-1]=word; currstr++; break;
               //default :
            }
            curr++;   
         }
      }
      for (int i=0;i<maxchars;i++)
         maschar[i][nCount]='\0';
      delete file;
      return nCount;
   }

#endif
