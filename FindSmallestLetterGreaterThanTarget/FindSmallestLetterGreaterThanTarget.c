

char nextGreatestLetter(char* letters, int lettersSize, char target){
    
    if(letters == NULL)
        return '0';
    
    
int start = 0, end =lettersSize; 
    
    while(start <end)
    {
       int mid = start + (end -start)/2; 
        
        if(letters[mid] <= target)
             start = mid+1;
        else 
            end = mid; 
      
        
    }
    
    
    return letters[start%lettersSize];

}
