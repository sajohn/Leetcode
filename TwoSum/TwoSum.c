int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
     if(!nums || numsSize <2 || !returnSize)
         return NULL;
    
  struct number_set* set = NULL;
  struct number_set* element;
  bool result = false;
  int* ret  = (int*) calloc(2, sizeof(int));
    if(ret == NULL)
        return NULL;
  
  for (int i = 0; i < numsSize; ++i) 
  {
    HASH_FIND_INT(set, &nums[i], element);
      if(element)
        continue;  
      else{
        element = (struct number_set *) calloc(1, sizeof(*element));
        element->value = nums[i];
        element->idx = i;
        HASH_ADD_INT(set, value, element);
      }
  } 
    
  for (int i = 0; i < numsSize; ++i) 
  {
      int tmp = target-nums[i];
      
    HASH_FIND_INT(set, &tmp, element);
    if (element) 
    {
        if(i != element->idx)
        {
            ret[0] = i; 
            ret[1] = element->idx;
            *returnSize = 2; 
        } 
    }
   
  }
 
  /* Destroy the hashset */
  struct number_set* curr;
  struct number_set* tmp;
  HASH_ITER(hh, set, curr, tmp) {
    HASH_DEL(set, curr);
    free(curr);
  }
  
   return ret;  
    
}
