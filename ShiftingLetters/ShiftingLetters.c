

char * shiftingLetters(char * s, int* shifts, int shiftsSize){
   if(s == NULL)
       return NULL; 
   if(shifts == NULL || shiftsSize == 0)
       return s; 
     int sum = shifts[shiftsSize-1]; 
    
  for(int i =shiftsSize-1; i>=0; i--){
      s[i] = 'a' + (sum + (s[i] - 'a') )%26;
      sum += (i!=0? shifts[i-1]: 0)%26;
  }
    
    return s; 
}
