

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct hash{
    int key; 
    int val;
    UT_hash_handle hh; 
    
}hash;

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
      if(nums1 == NULL || nums2 == NULL || nums1Size == 0 || nums2Size == 0)
          return NULL; 
    
    int* ret = (int*)calloc(nums1Size, sizeof(int));
    int* stack = (int*)calloc(nums2Size, sizeof(int));
    *returnSize = 0; 
    if(stack == NULL || ret == NULL)
        return NULL;
    
    int top = -1, j = 0, val =0; 
    struct hash *guser = NULL, *element; 
    
    for(int i = nums2Size-1 ; i >=0 ; i--) {  
           
                  while(  top != -1 && stack[top]< nums2[i] ) {
                      top--;
                  } 
                 
                 if(top == -1) {
                     val = -1; 
                      
                 } else {
                         val = stack[top];
                 }
        
                  element = (struct hash*)calloc(1, sizeof(hash));
                    if(element == NULL)
                        return NULL;

                     element->key = nums2[i]; 
                     element->val = val;
                     HASH_ADD_INT(guser, key , element);
        
                 stack[++top] = nums2[i];
        
              }
             
        for(int i =0; i <nums1Size; i++)
        {
            HASH_FIND_INT(guser, &nums1[i], element);
            
            if(element == NULL)
                return NULL; 
            ret[(*returnSize)++] = element->val;
            
            HASH_DEL(guser, element);
            free(element);
        }

    
  return ret; 
}
