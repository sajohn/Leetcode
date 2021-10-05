int max (int a, int b)
{
    return (a>b? a:b);
}
int CheckfromMiddlePalindrome(char* s, int left, int right, int len){
    
    if(left > right || s == NULL)
        return 0; 
bool flag = false; 
    
    while(left>=0 && right < len && (s[left] == s[right])) {   
  
        left--; 
        right++; 
        flag = true; 
    }
 

left++; right--; //Just to adjust length

if(flag == false)
    return 1; 


  return right -left +1; 

}
    

char * longestPalindrome(char * s){
    
       if(s == NULL)
        return ""; 
  int len = strlen(s);
    if(len <=1)
        return s; 
  char* ret = (char*)calloc(len+1, sizeof(char));
    if(ret == NULL)
        return NULL;
    
    int maxval = 0, maxsofar = 0,start =0, end =0; 
 
    for(int i = 0; i < len; i++) {
        
     int len1 =  CheckfromMiddlePalindrome(s, i, i, len);
            
     int len2 =  CheckfromMiddlePalindrome(s, i, i+1, len);
      
      maxval = max(len1, len2);
       if(maxval> end-start) {
           maxsofar = maxval; 
           start = i -((maxval -1)/2); 
           end = i+ (maxval/2);

       }

    }
    
    strncpy(ret, &s[start],  maxsofar );

    return ret;
}

