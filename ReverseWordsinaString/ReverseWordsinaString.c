

char * reverseWords(char * s)
{
 if(!s || strlen(s) <=1)
     return s;
    
    int len = strlen(s);
    
    char* dst = (char*)calloc(len+1, sizeof(char));
    
       if(!dst)
        return NULL;
    
    dst[len] = '\0';
    
    char* start = s;
    char* end = s+len-1;
    while(*start == ' ')
       start++;
    while(*end == ' ')
        end--;
    
    const char pat[2] = " ";
               
   char*  token = strtok(start, pat);
   int val = strlen(token);
    char* tmp = (char*)calloc(strlen(token)+1, sizeof(char));
                if(tmp == NULL)
                    return NULL;
    
    if(token)
        strncat(dst+len-val, token, strlen(token));
    
     while(token!= NULL )
     {
         token = strtok (NULL, " ");
            if(token)
            {
                tmp = (char*)realloc(tmp, strlen(dst+len-val)+1 *sizeof(char));
                if(tmp == NULL)
                    return NULL;
                int tmplen = strlen(dst+len-val)+1;
                strncpy(tmp, dst+len-val, strlen(dst+len-val)+1);
                 val = val+1;//For space
                 val = val + strlen(token);

                strncpy(dst+len-val, token, strlen(token));
                strncat(dst+len-val, " ", 1);

                strncat(dst+len-val, tmp, tmplen);
            }
     }
    free(tmp);
    
    return dst+len-val;
}


