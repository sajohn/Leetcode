

bool repeatedSubstringPattern(char * s){
    if(s == NULL)
        return true; 
    
    int len = strlen(s);
    if(len ==1)
        return false; 
    int mid =  len/2; ; 
 
 for(int i = mid; i>=1; i--){
     if(len%i != 0 )
         continue; 
     int k =i; 
       while(k <= len -i){
           
           if(strncmp(s, s+k, i)==0)
               k+=i;
           else
              break; 
       }
    if(k == len)
        return true; 
    }

    return false;
}
