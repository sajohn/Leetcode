/*
After counting first cut with n/3 ones we set a variable as we know the string can be cut from there untill 
we find count of 1's become more than n/3 (ways1 will increment)

                      cut1 cut2 cut3   (3 times)
                         ^   ^   ^
 "1001 | 0 | 0 | 0 | 101 | 0 | 0 | 110"
       V   V   V   V
    cut1 cut2 cut3 cut4 (4 times)
*/
int numWays(char * s)
{
    int len = strlen(s);
    
  if(s == NULL )
      return 0;
    
  int count =0, ways =0, ways1 =0, ways2 =0; 
   long mod =  1000000007;
    for(int i = 0; i < len; i++)
        if(s[i]-'0' == 1 )
            count++; 
     
    if(count == 0)
        return ((long)(len-1)*(long)(len-2)/2)%mod;
    
     if(count%3)
         return 0;
  

 for(int i = 0; i < len; i++)
 {
   if(s[i]-'0' == 1 )
            ways++;  
     
     if(ways == count/3)
         ways1++;
     
     if(ways == 2*count/3)
         ways2++;  
     
 }
    
    

    
    return ((long)ways1*(long)ways2)%mod;
}
