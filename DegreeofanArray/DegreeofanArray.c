typedef struct Degree
{
    int idx[2]; 
    int value;
    int count; 
    UT_hash_handle hh; 
}Degree; 

int name_sort(Degree *a, Degree *b) {
    return (b->count - a->count);
}
int findShortestSubArray(int* nums, int numsSize){
    
    if(nums== NULL || numsSize == 0)
        return 0; 
    
    Degree *g_users = NULL, *element; 
    int count =0, max = INT_MIN, val =0, max2 = INT_MAX; 
    
    for(int i =0; i <numsSize; i++)
    {
        count = 0; 
        HASH_FIND_INT(g_users, &nums[i], element);
        if(element == NULL)
        {
            element = (Degree*)calloc(1, sizeof(*element));
            if(element == NULL)
                return -1; 
         
            element->value = nums[i];
            element->idx[0] = i; 

            element->count++; 
            HASH_ADD_INT(g_users, value, element);
        }
        else
        {   
            element->idx[1] = i; 
            element->count++; 
          
        }
    }
    
    
     Degree *s;
    HASH_SORT(g_users, name_sort);
   
    for (s = g_users; s != NULL; s = (Degree*)(s->hh.next)) {
       if(s->count >= max && s->count>1)
       {
           
           if(s->idx[1] - s->idx[0] <=max2)
           {
             max = s->count;   
             max2 = (s->idx[1] - s->idx[0]);
            
           }
           
       }
        
    }
    
    
    return (max2!= INT_MAX? max2+1: 1); 
    
}
