typedef struct {
    
    int val; 
    char character;
}Hexspeak; 



char * toHexspeak(char *num){
    
    
    if(num == NULL)
        return NULL; 
    
     Hexspeak hs[8] = { {0,'O'}, {1, 'I'}, {10, 'A'}, {11,'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

    long number = (long)atol(num);
   char* retbuff = (char*)calloc(32, sizeof(char));
    if(retbuff== NULL)
        return NULL;  
    
    char buffer[32] = {0};
    int k = 31;
    long tmp = 0; 
    
    buffer[k--] = '\0';

    while(number != 0)
    {
        tmp = (long)number%16; 
        if(tmp >=0 && tmp <=9){
            if(tmp > 1){
             strncpy(retbuff, "ERROR", strlen("ERROR"));            
              return retbuff; 
            }
            else
                buffer[k--] = hs[tmp].character;   
        } else {
            buffer[k--] = hs[tmp%16 - 8].character;
        }
        
        number/=16; 
    }
    


    strncpy(retbuff, &buffer[k+1], 31-k);    
   return retbuff;

}
