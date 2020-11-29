

int maxNumberOfBalloons(char * text)
{
      int len = strlen(text);
    
     if(text == NULL || len <7)
         return 0;
    
    int count = 0, countarr[26]= {0}, min = INT_MAX;
    
    for(int i=0; i < len; i ++)
        if(text[i] == 'a' || text[i] == 'b' || text[i] == 'l' || text[i] == 'n' || text[i] == 'o')
          countarr[text[i]-'a']++;
    
     for(int i=0; i < 26; i ++)
         if(countarr[i]>0)
             min = (countarr[i] < min? countarr[i]:min);
    
     if(countarr['a'-'a' ]==0 || countarr['b'-'a']==0 || countarr['l'-'a']==0 || countarr['n'-'a']==0 || countarr['o'-'a'] ==0)
         return 0;
    
     if(min != 0 )
     {
         if( countarr['l'-'a'] >=2*min && countarr['o'-'a'] >=2*min )
            return min;
        else
        { 
            int max =  (countarr['l'-'a'] < countarr['o'-'a'] ? countarr['l'-'a']: countarr['o'-'a']);

            if(max/2>=min)
                return min;
            else
                return max/2;
        }
     }
   
       return 0;
}
