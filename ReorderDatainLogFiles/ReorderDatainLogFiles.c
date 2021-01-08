

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct Log
 {
     char* string;
     char* identifier;
     int index; 
 };

int cstring_cmp(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
	/* strcmp functions works exactly as expected from
	comparison function */ 
} 
 
int sort_items(const struct Log **p1, const struct Log **p2) {
//     assert(item && item2);
   struct Log *a = *(struct Log **) p1;
   struct Log *b = *(struct Log **) p2;

    if(strcmp(a->string, b->string) != 0){
        return strcmp(a->string, b->string);
       }
    else {
      return strcmp(a->identifier, b->identifier);
    }

}

/* C-string array printing function */ 
void print_cstring_array(char **array, size_t len) 
{ 
    size_t i;
 
    for(i=0; i<len; i++) 
        printf("%s | ", array[i]);
 
    putchar('\n');
} 

char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){

       
   // (tokenize by space and put in order)
    
    char* token = NULL, *token1=NULL, *tmpstr;
    char** ret;
    int size =0, dig[logsSize];
    *returnSize = 0;
    
    struct Log* log[logsSize];

    for(int k =0, j = 0; k < logsSize; k++)
    {
  
        tmpstr =  (char*)calloc(strlen(logs[k])+1, sizeof(char));
        strncpy(tmpstr, logs[k], strlen(logs[k]));
        
        token = strtok(tmpstr, " ");
         
        token1 = strtok(NULL, " ");
    
        if(!isdigit(token1[0])) {       
            log[size]= (struct Log*)calloc(1, sizeof(struct Log));
            if(log[size] == NULL)
              return NULL;

            log[size]->identifier = (char*)calloc(strlen(token)+1, sizeof(char));
            strncpy(log[size]->identifier, token, strlen(token));
            
            log[size]->string = (char*)calloc(strlen(logs[k])-strlen(token), sizeof(char));
            strncpy(log[size]->string, logs[k]+strlen(token)+1, strlen(logs[k])-strlen(token)-1);
 
            log[size++]->index = k;
      }
      else {
          dig[j++] = k;
      }
        free(tmpstr); 
        tmpstr = NULL;
    }

    qsort(log, size, sizeof(struct Log*), sort_items);
    ret = (char**)calloc(logsSize, sizeof(char*));
    if(ret == NULL)
        return NULL;
    
    for(int i =0, k = 0, j =0; i < logsSize ; i++, k++)
    {
        if(k < size){
            ret[i] = calloc(strlen(logs[log[k]->index])+1, sizeof(char));
            strncpy(ret[i], logs[log[k]->index], strlen(logs[log[k]->index])+1);   
        }
        else{
            ret[i] = calloc(strlen(logs[ dig[j] ])+1, sizeof(char));
            strncpy(ret[i], logs[dig[j]], strlen(logs[ dig[j] ]   )+1 );   
            j++;            
        }
   
    }
     *returnSize = logsSize;
        return ret;
}
