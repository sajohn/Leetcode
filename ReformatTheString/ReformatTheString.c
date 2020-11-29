

char * reformat(char * s)
{
   if(s==NULL)
       return "";
    int len = strlen(s);
int countalpha=0;
    for(int i =0; i < len; i++)
        if(isalpha(s[i]))
          countalpha++;
  char* ret = (char*)calloc(len+1, sizeof(char));
    if(ret== NULL)
        return "";
    
   bool alpha = false;
    if(abs((len -countalpha) -countalpha)<=1)
    {//if count of alpha > numerals choose alpa else choose numerals
       if(len -countalpha > countalpha)
           alpha = false;
        else 
            alpha = true;
        
        int j =0, k=1;
      for(int i =0; i < len; i++)
      {
          if(alpha) 
          {
            if( isalpha(s[i]))
             {
              ret[j] = s[i];
              j+=2;
             }
             else
            {
              ret[k] = s[i];
              k+=2; 
            }
          }
          else
          {
              if( isalpha(s[i]))
             {
              ret[k] = s[i];
              k+=2;
             }
             else
            {
              ret[j] = s[i];
              j+=2; 
            }
          }
         
      }
    }
    else
        return "";
        
        return ret;
}
