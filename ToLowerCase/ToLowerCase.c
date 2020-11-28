

char * toLowerCase(char * str)
{

    if(str == NULL)
        return NULL;
    
    int len = strlen(str);
  
    for(int i = 0; i < len; i++)
    {
        if(isalpha(str[i])  && (str[i] >='A' && str[i]<='Z' ))
         {
             str[i]= str[i]-'A'+'a';
          }
    }
    return str;     
}
           
           
 
