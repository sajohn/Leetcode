
typedef struct Hash{
    int key;
    int count;
    UT_hash_handle hh; 
}Hash;

int cmpfunc(Hash* a, Hash* b){
    
    return ( ((Hash*) a)->key - ((Hash*) b)->key   );
}

int minimumRounds(int* tasks, int tasksSize){
    Hash* guser = NULL, *element, *tmp; 
    
    if(tasks == NULL || tasksSize == 0)
        return -1; 
    
 
    int count = 0; 
    for(int i =0; i < tasksSize; i++){
        
        HASH_FIND_INT(guser, &tasks[i], element);
        
        if(element == NULL)
        {
            element = (Hash*)calloc(1, sizeof(Hash));
            if(element == NULL)
                return -1;
            element->key = tasks[i];
            element->count = 1; 
            
            HASH_ADD_INT(guser, key, element);
        }
        else{
            element->count += 1; 
        }
        
        
    }
    
    HASH_SORT(guser, cmpfunc);
    int remainder = 0; 
    HASH_ITER(hh, guser, element, tmp)
    {

              if(element->count <= 1)
                  return -1; 
              else{
                    remainder = element->count %3;
                  
                     if (remainder == 0){
                         count+= element->count /3; 
                     }
                     else if(remainder == 1){
                         count += ((element->count - 4)/3 + 2);
                     }
                     else if(remainder == 2){
                         count += ((element->count - 2)/3 + 1);
                     }
                }
    }
    
    return count; 

}
