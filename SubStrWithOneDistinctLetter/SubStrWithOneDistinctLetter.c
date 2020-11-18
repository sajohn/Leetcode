

int countLetters(char * S)
{
    
    int count[26] = {0};
    int ways =0; 
    int len =0;
     if(S == NULL || (len = strlen(S) )== 0)
         return 0;
    
    for(int i =0; i < len; i++)
    {
        if(S[i] == S[i+1])
             count[S[i]-'a']++;
        else 
        { 
            count[S[i]-'a']++;
            ways += ( (count[S[i]-'a']*  (count[S[i]-'a']+1))/2);
            count[S[i]-'a']= 0;
        }
    }
  return ways; 
}
