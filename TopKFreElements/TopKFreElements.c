
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct numberset
{
  int val;
  int freq; 
  UT_hash_handle hh;
    
};
int cmpfunc(struct numberset* a, struct numberset* b)
{
  
  if(a->freq > b->freq)  
        return -1;
    else  if(a->freq < b->freq)  
        return 1;
    else 
        return 0;
    
    return -1;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    
    if(!nums || numsSize <1 || k<1 || numsSize <k)
        return NULL;
    if(numsSize ==1 && k==1)
    {
        *returnSize =k;
        return nums;
    }
  
  int* ret = (int*)calloc(k, sizeof(int));
    if(ret== NULL)
        return NULL;
 
 struct numberset* set = NULL, *element;
   
    for(int i =0; i < numsSize; i++)
    {
        HASH_FIND_INT(set, &nums[i], element);
        if(element)
            element->freq++;
       else{
        element = (struct numberset*)calloc(1, sizeof(struct numberset));
            if(element == NULL)
              return NULL;
            
                element->val = nums[i];
                element->freq = 1;
            
            HASH_ADD_INT(set, val, element);
       }
    }
       
     
    *returnSize =k;  
     /* Destroy the hashset */
  struct numberset* curr;
  struct numberset* tmp;
    
  HASH_SORT(set, cmpfunc);  
    
  struct numberset *s;


    
  int i =0;
  HASH_ITER(hh, set, curr, tmp) {
      if(i<k)
          ret[i++] = curr->val;
    HASH_DEL(set, curr);
    free(curr);
  }
    
return ret;
        
    
}
