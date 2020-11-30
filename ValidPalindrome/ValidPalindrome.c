

bool isPalindrome(char * s)
{
    if(s == NULL)
        return false;
    
    int len = strlen(s);
    if(len ==1)
        return true;
    
    
    int l= 0, r = len-1;
    
   for(int l =0, r = len-1 ; l<r; l++, r--)
    {
       while( l<r && (!isalnum(s[l])))
             l++;
     

     while(l<r &&  (!isalnum(s[r])))
             r--;
        
    if( l<r && tolower(s[l])!= tolower(s[r]))
            return false;
   
    }
    
    return true;
}
