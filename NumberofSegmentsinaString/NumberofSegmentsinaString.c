

int countSegments(char * s)
{
    int len = strlen(s);
    if(s == NULL)
        return -1;
     if(len == 0)
         return 0;
    
    char* token = NULL;
    char delm[2]={0};
    delm[0] = ' ';
    delm[1] = '\0';
     int count = 0;
    
    token = strtok(s, delm);
   
    while(token != NULL)
    {
        count++;
        token = strtok(NULL, delm);
    }
    
    return count;
}
