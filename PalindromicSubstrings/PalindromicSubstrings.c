int CheckfromMiddlePalindrome(char* s, int left, int right, int len){
    
    if(left > right || s == NULL)
        return 0; 

    int rlen = 0; 

    while(left>=0 && right < len) {   
      
        if(s[left--] != s[right++])
            break;
              
            rlen++; 
    }
   
   return rlen;
}
    
 

int countSubstrings(char * s){
    
    if(s == NULL)
        return 0; 
  int len = strlen(s);
    if(len <=1)
        return len; 
  
    int count =0; 
    for(int i = 0; i < len; i++) {
        
        count += CheckfromMiddlePalindrome(s, i, i, len);
            
        count += CheckfromMiddlePalindrome(s, i, i+1, len);
    }

    return count;
}
