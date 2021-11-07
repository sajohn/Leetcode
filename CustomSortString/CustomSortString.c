

char * customSortString(char * order, char * s){
    
    if(order == NULL || s == NULL)
        return NULL; 
    
    int orderlen = strlen(order);
    int slen = strlen(s);
    
    char* ret = (char*)calloc(1+slen, sizeof(char));
    if(ret == NULL)
        return NULL; 
    
    int counts[26] = {0}, k =0;
    
    for(int i =0;  i< slen; i++)
        counts[s[i] - 'a']++;
  
    
    for(int i = 0; i < orderlen; i++)
    {
        while(counts[order[i]-'a']>0){
            
            ret[k++] = order[i];
            
            counts[order[i]-'a']--; 
        }
      }
    for(int i = 0; i < 26; i++)
    {
        while(counts[i]>0){
         ret[k++] = i+'a';
         counts[i]--;
        }
        
    }
    ret[slen] = '\0';
    return ret; 

}
