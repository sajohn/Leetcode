

void reverseString(char* s, int sSize){
    
    if(sSize==0 || s == NULL)
        return;
    
    int first=0, last=0;
    first = 0; 
    last = sSize-1;
    
    if( strlen(s) < sSize)
        last = strlen(s)-1;
    
    while(first<=last)
    {
        char tmp = s[first]; 
        s[first] =  s[last];
        s[last] =  tmp;
        first++;
        last--;
    }

}

char * reverseStr(char * s, int k)
{
    int len = strlen(s);
    
    if(s == NULL || len == 0)
        return NULL;
    
    if(len <= k)
    {
       reverseString(s, len);
       return s; 
    }
    else
    {
        int ptr =0;
        while(len -ptr >0)
        {
             reverseString(s+ptr, k);
             ptr += 2*k;
        }
    }
    
    
    return s;
}
