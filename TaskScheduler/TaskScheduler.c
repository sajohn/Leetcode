
typedef struct Tasklet{
    
    char taskName[2];  //Key within Str for hash
    int taskCount; 
    UT_hash_handle hh;
    
}Tasklet;


int sort_count(struct Tasklet* t1, struct Tasklet* t2)
{
    return (t2->taskCount -t1->taskCount);
}

int Min(int a , int b)
{
        return (a<b? a:b);    
}
int Max(int a , int b)
{
        return (a>b? a:b);    
}

int leastInterval(char* tasks, int tasksSize, int n) {    
    
    if(tasks == NULL || tasksSize == 0)
        return -1; 
    
    Tasklet* guser= NULL, *element= NULL, *tmp = NULL;
    
    for(int i =0; i < tasksSize; i++){
       char tmp[2] = {0}; 
        tmp[0] = tasks[i];
        tmp[1] = '\0';
        
        HASH_FIND_STR(guser, tmp, element);
        if(element) {
            element->taskCount++; 
        } else {
            element = (Tasklet*)calloc(1, sizeof(Tasklet));
            if(element == NULL)
                return -1; 
           
            element->taskName[0] = tasks[i];
            element->taskName[1] = '\0';
            element->taskCount = 1; 
            HASH_ADD_STR(guser, taskName, element);
        }
    }
    
    HASH_SORT(guser, sort_count);
    
    if(n == 0)
        return tasksSize; 
    
    
    int maxcount = guser[0].taskCount -1; 
  
   int idleSlots = (guser[0].taskCount -1) * (n);
    
  bool first = true; 
    /* free the hash table contents */
    HASH_ITER(hh, guser, element, tmp) {
        if(first == true) {
          first = false; 
          goto CC;
   
        }  else if(idleSlots>0) {
            idleSlots -=  Min(maxcount , element->taskCount);
          } 
CC:
      HASH_DEL(guser, element);
      free(element);
    } 
    

    return tasksSize+Max(0, idleSlots);
    
}
