

void reverseString(char* s, int sSize){
    
    if(sSize==0 || s == NULL)
        return;
    
    if(sSize <2)
        return;
    
    int first=0, last=0;
    first = 0; 
    last = sSize-1;
    
    while(first<last)
    {
        s[first] =  s[first]^ s[last];
        s[last] =  s[last]^ s[first];
        s[first] = s[first]^s[last];
        first++;
        last--;
    }

}
