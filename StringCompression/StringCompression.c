int CopyChars(char* str, char tmp, int idx, int count)
{
    if(str == NULL || idx <0 || count < 0)
        return -1; 
    
    char tmpbuff[10] = {0};
    if(count == 1){
             str[idx] = tmp; 
             idx++;
            } else {
                str[idx] = tmp; 
               if(count > 9){
                   sprintf(tmpbuff, "%d", count);
               int len = strlen(tmpbuff);
               for(int j =0; j < len; j++)
                   str[idx+1+j] = tmpbuff[j];
                
                idx +=len+1; 
               } else {
                   str[idx+1] = count+ '0';
                    idx+=2;
                }
            }
    return idx;
}

int compress(char* chars, int charsSize){

    if(chars == NULL || charsSize == 0)
        return -1; 
    
    int count =0,  k =0;
    char tmp = chars[0];
    
    for(int i = 0; i < charsSize; i++)
    {
        if(tmp == chars[i])
        {
            count++; 
        }else{
              k = CopyChars(chars, tmp,k, count);
            count =1; 
            tmp = chars[i];
        }
 
    }
 
    k = CopyChars(chars, tmp,k, count);           
    
    return k; 
}
