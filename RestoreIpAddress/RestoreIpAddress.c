

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//IP address as 3: 3: 3: 3 == max 12 digits
//IP address as 1: 1: 1: 1 == min 4 digits 
//Each octet can have 1-3 max digits
//Problem reduces to new provblem once first octet is filled...
//each octet can have values 0-255 as values

bool isValid(char* val)
{
    if(val == NULL)
        return NULL; 
    int len = strlen(val);
    
    if(len > 3)
        return false; 
    
    int tmpval = atoi(val); 
     if(tmpval < 0 || tmpval > 255)
        return false; 
    
    sprintf(val, "%d", tmpval);
   
    if((atoi(val) >=0 && atoi(val)<=255) )
    {
        if( ( tmpval == 0 && len >1) ||
             (strlen(val) <len)
          )
            return false; 
        return true;
    }
    
    return false; 
}

void CreateIpAddress(char* s, int* returnSize, char** ret, int octet, int len, char* tmp, int tmpidx)
{
    if(s == NULL || tmp == NULL  || octet >4)
        return; 
   int count = 0; 
    if(octet == 4 )
    {
        if( len == 0){
            char* token; 
            char delim[2] = ".";
            int offset = 0; 
            char* buff = (char*)calloc(strlen(tmp)+1, sizeof(char));
            if(buff == NULL)
                return ; 
            strncpy(buff, tmp, strlen(tmp)+1);
            
            token = strtok(buff, delim);
        
            ret[*returnSize] = (char*)calloc(16, sizeof(char));
            
            while(token != NULL){
                if(!isValid(token)){
                    free(ret[*returnSize]);
                  return; 
                }
                sprintf(token, "%d", atoi(token));
                strcat(ret[*returnSize], token);
                if(count <3)
                 strcat(ret[*returnSize], ".");
                count++; 
                token = strtok(NULL, delim);  
            }
          (*returnSize)++; 
            free(buff);
        }
        return; 
    }
 
    
    for(int i = 0; i < len && tmpidx<16; i++ )
    {
        tmp[tmpidx] = s[i];
        if(octet <3)
          tmp[tmpidx+1] = '.';
        
        tmp[tmpidx+2] = '\0';
        CreateIpAddress(s+i+1, returnSize, ret, octet+1, len-i-1, tmp, tmpidx+2);
        tmp[tmpidx+1] = '\0';
        tmp[tmpidx+2] = '\0'; 
       
        tmpidx++; 
    }
    
    
}

char** restoreIpAddresses(char * s, int* returnSize){

     *returnSize = 0; 
    if(s == NULL)
        return NULL; 
    

    char** result = (char**)calloc(30, sizeof(char*));
      if(result == NULL)
        return NULL; 
    char* tmpbuff = (char*)calloc(30,sizeof(char));
    if(tmpbuff == NULL)
        return NULL; 
    
    CreateIpAddress(s, returnSize, result, 0, strlen(s), tmpbuff, 0);
    free(tmpbuff);
    return result; 
}
