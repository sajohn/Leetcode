typedef struct Hash {
    
    int *idx;
    int val; 
    int size; 
    UT_hash_handle hh; 
}Hash;


typedef struct Solution{
    int size; 
    struct Hash** h; 
} Solution;

Hash *guser = NULL;
Solution* solutionCreate(int* nums, int numsSize) {
    
    if(nums == NULL || numsSize == 0)
        return NULL; 
    
    Solution* obj = (Solution*)calloc(1, sizeof(Solution));
    if(obj == NULL)
        return NULL; 
     Hash *element = NULL; 
    
    
    obj->size = numsSize; 
    obj->h = &guser; 
    for(int i = 0; i < numsSize; i ++)
    {
        HASH_FIND_INT(guser, &nums[i], element);
        
            if(element)
            {
                element->idx = (int*)realloc(element->idx, (element->size+1) * sizeof(int));
                element->idx[element->size++] = i; 
            }else {
                element = (Hash*)calloc(1, sizeof(Hash));
                if(element == NULL)
                    return NULL; 
                element->idx = (int*)calloc(element->size+1 , sizeof(int));
                element->idx[element->size++] = i; 
                element->val = nums[i];
                
                HASH_ADD_INT(*(obj->h), val, element);
            }  
    }
    
    srand(time(0));
    
    return obj; 
    
}

int solutionPick(Solution* obj, int target) {
    
    if(obj == NULL)
        return -1; 
    
    Hash* element = NULL;
    
    
    if(*(obj->h))
       HASH_FIND_INT(*(obj->h), &target, element);
    
    if(element == NULL)
        return -1; 
    else{
            
       if(element->size == 0)
           return -1; 
       else if(element->size == 1)
           return element->idx[0];
        else{
            
            return (element->idx[rand()%element->size]);
        }
        
    }
       
    return -1; 
}

void solutionFree(Solution* obj) {
    if(obj)
    {
       
            Hash *current_user, *tmp;
            HASH_ITER(hh, *(obj->h), current_user, tmp) {
            HASH_DEL( *(obj->h), current_user);  /* delete; users advances to next */
            free(current_user);             /* optional- if you want to free  */
         }
        
        free(obj);
    }
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 
 * solutionFree(obj);
*/
