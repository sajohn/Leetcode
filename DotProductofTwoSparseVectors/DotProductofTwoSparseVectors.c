


typedef struct {
    int val; 
    int idx; 
   struct SparseVector* next;  
} SparseVector;


SparseVector* sparseVectorCreate(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return NULL; 
    
 
  SparseVector* head = NULL;  SparseVector dummy; 
    
  head = &dummy; 
  head->next = NULL;   

  for(int i=0; i < numsSize; i++)
  {
      if(nums[i]!=0){
        
    head->next = (SparseVector*)calloc(1, sizeof(SparseVector));
    if(head->next == NULL)
        return NULL;
         head = head->next;
         head->val = nums[i];
         head->idx = i;
         head->next = NULL; 
        
      }
          
  }
    
    return dummy.next; 
}

// Return the dotProduct of two sparse vectors
int sparseVectordotProduct(SparseVector* obj, SparseVector* vec) {
    
 if(obj == NULL || vec== NULL)
     return 0; 
    
    int result = 0; 
    
    while(obj && vec)
    {
        
        if(obj->idx== vec->idx)
        {
            result += obj->val * vec->val;
            
            obj = obj->next; 
            vec = vec->next; 
        }
        else{
             if(obj->idx> vec->idx)
                 vec = vec->next; 
            else  if(obj->idx < vec->idx)
                obj = obj->next; 
        }
    }

  return result; 
}

/**
 * Your SparseVector struct will be instantiated and called as such:
 * SparseVector* v1 = sparseVectorCreate(nums1, nums1Size);
 * SparseVector* v2 = sparseVectorCreate(nums2, nums2Size);
 * int ans = sparseVectordotProduct(v1, v2);
*/
