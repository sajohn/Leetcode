

typedef struct{
   char *str;
   int val;
}numeral;

int stringToInt(char* s, numeral* nume, int* skip)
{
    
    if(s != NULL )
    {
       for(int i = 0; i<15; i++)
       {
          if(strncmp(nume[i].str, s, 1) == 0)
          {
              if(strlen(s)>1)
              {
                  if(strncmp(nume[i].str, "I", 1) ==0)
                  {
                     if(s[1] == 'X')
                     {
                         *skip = 2;
                         return 9;
                     }
                     else if( s[1] == 'V')
                     {
                          *skip = 2;
                          return 4;
                     }
                      else{*skip = 1;
                          return 1;}
                  }
                 else if(strncmp(nume[i].str ,"X", 1) ==0)
                 {
                     if(s[1] == 'L')
                     {
                          *skip = 2;
                         return 40;
                     }
                     else if( s[1] == 'C')
                     {
                          *skip = 2;
                          return 90;
                     }
                      else{*skip = 1;
                          return 10;}
                 }
                 else  if(strncmp(nume[i].str, "C", 1) ==0)
                 {
                     if(s[1] == 'D')
                     {
                          *skip = 2;
                         return 400;
                     }
                     else if( s[1] == 'M')
                     {
                          *skip = 2;
                          return 900;
                     }
                      else{*skip = 1;
                          return 100;}
                 }
                 else
                 {
                       *skip = 1;
                      return nume[i].val;
                 }

              }
              else
              {
                   *skip = 1;
                  return nume[i].val;
              }
          }
           *skip = 0;
          
       }
    }
    *skip = 0;
    return 0;
}

int convertRomanToInt( char* s, int* skip)
{

     numeral nume[15] = {{"I",1},{"IV",4},{"V",5},{"IX",9}, {"X",10},{"XL",40},{"L",50},{"XC",90},
    {"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000},{"MMMM",4000},{"V'",5000}};

       int max =0 ;

       if(s != NULL)
       {
          max += stringToInt(s, nume, skip);
         if(*skip == 1)
            max+= convertRomanToInt(s+1, skip);
         else if(*skip == 2)
            max+= convertRomanToInt(s+2, skip);
         
           return max;
       }
     return 0;
}

int romanToInt(char * s)
{
   if(s == NULL)
       return 0;
    int skip =0; 
    return convertRomanToInt(s , &skip);
    
}


