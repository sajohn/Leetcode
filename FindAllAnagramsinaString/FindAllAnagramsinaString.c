

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize)
{
    int slen = strlen(s);
    int plen = strlen(p);
     
    
    if(s == NULL || p == NULL || slen == 0 || plen ==0 || slen == 0)
    {
        *returnSize =0;
        return NULL;
    }
    int countC[26] = {0};
    
    for(int i =0; i < plen; i++)
        countC[p[i]-'a']++;
    
    int * ret = (int*)calloc(slen, sizeof(int));
    if(ret == NULL){
        *returnSize =0;
        return NULL;
    }
    
    //Sliding window approach
    /* 1. check first character to match 
           a. if match decrease its count
           b. it next doesn't match put back the count of the previous index and contiue
           c. if count == 0 and len == plen its a match, put start index in result
           d. increase the count of start index and put back its count and count of string as well
          */
    
    int start =0, end =0, count = plen, k =0;
    
    while(end < slen)
    {
        if(countC[s[end++]-'a']-- >=1)
            count--;
        
        if(count == 0 )
            ret[k++] = start;
        
        
        if(end -start == plen && countC[(s[start++]-'a')]++ >=0 )
            count++;
        
    }
    *returnSize = k;
    return ret;

}
