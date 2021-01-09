int max(int a, int b)
{
    
    return (a>b? a:b);
}
    
int findLUSlength(char * a, char * b)
{
       
    int lena = strlen(a);
    int lenb = strlen(b);
  
    if(!a && !b)
        return -1;
    int i=0, j=0, count =0;
 
   for(int i =0; i<lena;i++ )
    {
      if(a[i]==b[j])
      {
          j++;
          count++;
      }
        
    }

    if((count ==lena || count == lenb) && lena == lenb)
        return -1;
    else
        return max(lena, lenb);
    
    
return -1;
}
