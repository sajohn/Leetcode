

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct 
{
    int count; 
    const char* domain;
    UT_hash_handle hh;
}cpHash;

char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize)
{
    cpHash *g_user = NULL, *element = NULL, *s = NULL;
    (*returnSize) =0; 
    if(cpdomains == NULL || cpdomainsSize == 0)
        return NULL;
     char delemit[] = " \t\r\n\v\f.";
        char* token, *tmpstr;
        int count =0, tokencount=0, hashcount =0;    
    for(int i =0; i< cpdomainsSize; i++)
    {        
        tmpstr = (char*)calloc(strlen(cpdomains[i])+1, sizeof(char));
        if(tmpstr == NULL)
            return NULL;
        
        strncpy(tmpstr, cpdomains[i], strlen(cpdomains[i]));
        count = atoi(tmpstr);
        
        token = strtok(tmpstr, delemit);
        if(token)
         tokencount = 1+strlen(token);
            
        while(token != NULL)
        {
            token = strtok(NULL, delemit);
            if(token != NULL)
            {
                if(cpdomains[i]+tokencount != NULL && strlen(cpdomains[i]+tokencount)!=0){
                // printf("-%s\n",cpdomains[i]+tokencount );
                    HASH_FIND_STR( g_user, cpdomains[i]+tokencount, element);
                }
                if(element)
                    element->count += count;
                else if(strlen(cpdomains[i]+tokencount)!=0)
                {
                    hashcount++;
                    element = (cpHash*)calloc(1, sizeof(*element));
                    if(element == NULL)
                        return NULL;

                    element->domain = (char*)calloc(strlen(cpdomains[i]+tokencount)+1, sizeof(char));
                    if(element->domain == NULL)
                        return NULL;
                    strncpy(element->domain,cpdomains[i]+tokencount,strlen(cpdomains[i]+tokencount));
                    element->count = count; 

                    HASH_ADD_KEYPTR( hh, g_user, element->domain, strlen(element->domain), element);
                }


                tokencount += (1+strlen(token));
                element = NULL;
            }
        }
        
     free(tmpstr); 
    }
    
    char** ret; 
    (*returnSize) = HASH_COUNT(g_user);
    
    ret = (char**)calloc(*returnSize, sizeof(char*));
    if(ret == NULL)
        return NULL;
    
    count =0, tokencount=0; 
    /* free the hash table contents */
    HASH_ITER(hh, g_user, element, s) {
        
        if(element)
        {
          ret[tokencount] = (char*)calloc( strlen(element->domain) +10 , sizeof(char));
          snprintf(ret[tokencount], strlen(element->domain) +10, "%d %s", element->count, element->domain);
          tokencount++;
        }
      HASH_DEL(g_user, element);
      free(element);
    }
    return ret;
}
    
