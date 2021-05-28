void createHex(int num, int* idx, char** result)
{
    
    if(num)
    {
        int tmp = abs(num%16); 
        num = num/16;
        
        createHex(num, idx, result);
        
        *result = (char*)realloc(*result, ((*idx)+1)* sizeof(char));
        
        if(tmp>=0 && tmp < 10)
            (*result)[(*idx)++] = tmp + '0';
        else if(tmp>=10 && tmp <=15)
            (*result)[(*idx)++] = tmp%10 + 'a';
    }
}



char * toHex(int num){
    
    if(num == 0 )
        return "0"; 
    if (num == -1)
        return ("ffffffff");
    if( num == INT_MAX) 
        return "7fffffff";
  if( num == INT_MIN) 
        return "80000000";
    
    char* result = NULL;
    int i =0; 
    bool isNeg= false; 
    
    
    if(num < 0) {
      isNeg = true;
      num = INT_MAX + (num + 1); ///This portion is done in a way that still INT_MAX representation should be maintained. 
    /*
        Trying to trick the number representation in hex format
    */
     }


    createHex(abs(num), &i, &result);
    result = (char*)realloc(result, (i+1)* sizeof(char));
     result[i] = '\0'; 

    if(isNeg){
        result[0] = 'f';
    }
   
  return result;       
}
