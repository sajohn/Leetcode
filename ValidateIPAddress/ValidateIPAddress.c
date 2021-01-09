
int CheckOctet(char* octet, int ver)
{
    if( strlen(octet) < 1 || octet == NULL )
     return 0;  

   int isValid =0;
   int i =0;

    while(octet[i]!= '\0')
    {
        if(ver == 1 && isdigit(octet[i++])) 
            isValid =1;
        else if(ver == 0 && isxdigit(octet[i++])) 
            isValid =1;
        else
          {
            isValid = 0;
            break;
          }          
    }
    return isValid;
}

char* CheckforIPV6(char* ip)
{
    if(!ip || (ip[strlen(ip) -1] == ':') || (ip[0] == ':'))
        return "Neither";
     
    char* token;
    const char s[2] = ":";
    token = strtok(ip, s);
      if(token == "" || token == NULL)
         return "Neither";
    
    int tokenCount = 0;

    while( token != NULL ) 
    {
       if( (token[0]== '0' && tokenCount ==0) || strlen(token)>4 || strlen(token)<1 )
        return "Neither";
       
      if(!CheckOctet(token, 0))
         return "Neither";
        
       token = strtok(NULL, s);
       if(token!=NULL)
        ++tokenCount;
     }
       return ((tokenCount == 7)? "IPv6": "Neither");
}

char* CheckforIPV4(char* ip)
{
    if(!ip || (ip[strlen(ip) -1] == '.') || (ip[0] == '.') )
        return "Neither";
     
    char* token;
    const char s[2] = ".";
    token = strtok(ip, s);
      if(token == "" || token == NULL|| strcmp(token, "256") ==0 ||  ip[strlen(ip)-1] == '.' || ip[0] == '.')
        return "Neither";
    
    int tokenCount = 0;
    
    while( token != NULL ) 
    {
       if(atoi(token) == 256)
           return "Neither";
 
       if( (token[0]== '0' && strlen(token)>1) || (token[0]== '0' && tokenCount ==0) || strlen(token)>3)
        return "Neither";
       
       if(!CheckOctet(token, 1))
         return "Neither";
        
       token = strtok(NULL, s);
       if(token!= NULL)
       tokenCount++;
     } 
      return ((tokenCount ==3)? "IPv4": "Neither");
}

char * validIPAddress(char * IP)
{    
    if(!IP )
        return "Neither";
    
    int len = strlen(IP);
    
    if(len < 7)
        return "Neither";
    
    char* tmp = IP;
    int isIPv6String =0;

    
  while(tmp!= NULL)
  {
    if(*tmp == ':')
    {
      isIPv6String =1;
        break;
    }
    else if(*tmp == '.')
    {
        isIPv6String  = 0;
        break;
    }
        
        tmp++;
}
     
for(int i = 0; i < len; i++){
     if(IP[i]== ':' || IP[i]== '.'  && i < len -1)
     {
         if(IP[i] == IP[i+1])
         return "Neither";
     }

   }
    
    if(isIPv6String)
       return CheckforIPV6(IP);
    else
       return CheckforIPV4(IP);      
  
}
