

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct hasNode
{
   int val; 
   int count; 
   UT_hash_handle hh; 
}hashNode; 
int cmpFunc( hashNode* a,  hashNode* b)
{
    return (a->val - b->val);
}


int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){

    *returnSize = 0; 
    if(arr1 == NULL || arr1Size == 0 || arr2 == NULL || arr2Size == 0)
        return NULL; 
    
    int *ret = (int*)calloc(arr1Size, sizeof(int));
    if(ret == NULL)
        return NULL; 
        
    hashNode *g_users = NULL, *element, *tmp; 
    
    int value =0,  count =0; ; 
    for(int i =0; i < arr1Size; i++)
    {
        value =arr1[i];
       HASH_FIND_INT(g_users,&value, element);
        if(element == NULL)
        {
            element = (hashNode*)calloc(1, sizeof(hashNode));
            if(element == NULL)
                return NULL; 
            
            element->val = arr1[i];
            element->count =1; 
            HASH_ADD_INT(g_users, val, element);
        }
        else
        {
            element->count++;
        }
    }
    
    for(int i =0; i < arr2Size; i++)
    {
        value = arr2[i];
         HASH_FIND_INT(g_users,&value, element);
        if(element == NULL)
        {
            return NULL;
        }
     
        while(count< element->count)
        {
          ret[(*returnSize)++] = arr2[i];
          count++;
        }
        count =0;
        HASH_DEL(g_users, element);
        free(element);
    }
  
    HASH_SORT(g_users, cmpFunc);

    
    HASH_ITER(hh, g_users, element, tmp) {
        count =0; 
        while(count < element->count )
        {  
            ret[(*returnSize)++] = element->val;  
            count++;
        }
        
    HASH_DEL(g_users, element); 
    free(element);           
  }
    
    return ret; 
}
