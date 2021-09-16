

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct map
{
    int val; 
    char* string;
};

struct map m[10] = { {0,""},{1,""},{2, "abc"},{3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"},{7, "pqrs"},{8, "tuv"},{9, "wxyz"}};

void combine(char* digits, int ridx, int cidx, char** ret, int* returnSize, char* tmp) {
    
    if(digits== NULL || returnSize == NULL || tmp == NULL)
        return; 
    
    
    if(ridx == strlen(digits)) {
        tmp[ridx] = '\0';
      
        int len = strlen(tmp);
        ret[*returnSize] = calloc(len+1, sizeof(char));
        strncpy(ret[*returnSize], tmp, len);

         (*returnSize)++;
        return; 
    }
    
   int len = strlen((m[(digits[ridx]-'0')].string));
   
    for(int i = 0; i < len; i++){
        tmp[ridx] = m[(digits[ridx]-'0')].string[i];
        combine(digits, ridx+1, 0, ret, returnSize, tmp);
    }
    
}

char ** letterCombinations(char * digits, int* returnSize){

    //Add map to hash set
    //Get first string for last digit from map
    //Permute final string
    
 *returnSize =0;
int len = strlen(digits);
if(len == 0 || digits == NULL )
    return NULL; 
  
int nums =0, total = 1; 

for(int i=0; i < len; i++)  
   total *=  strlen((m[(digits[i]-'0')].string));

  char** ret = (char**) calloc(total, sizeof(char*));
    if(ret == NULL)
        return NULL; 
    
  char* tmp = calloc(len+1, sizeof(char));
    if(tmp == NULL)
        return NULL; 

  combine(digits, 0, 0, ret, returnSize,tmp);    
    
    return ret;
}
