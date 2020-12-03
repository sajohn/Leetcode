
typedef struct number_set 
{
    int value;
    int freq;
    UT_hash_handle hh; 
}; 



int majorityElement(int* nums, int numsSize)
{
    
   if( nums==NULL || numsSize ==0)
       return -1;
  struct number_set* set = NULL;
  struct number_set* element;
  int result = 0, max_so_far = INT_MIN;
  
  for (int i = 0; i < numsSize; ++i) 
  {
    HASH_FIND_INT(set, &nums[i], element);
    if (element) 
      element->freq++;
    else{    
        element = (struct number_set *) malloc(sizeof(*element));
        element->value = nums[i];
        element->freq = 1;
        HASH_ADD_INT(set, value, element);
    }
     if( element->freq > max_so_far)
      {
            max_so_far = element->freq;
            result = nums[i];
        }
   
  }
 
  /* Destroy the hashset */
  struct number_set* curr;
  struct number_set* tmp;
  HASH_ITER(hh, set, curr, tmp) {
    HASH_DEL(set, curr);
    free(curr);
  }
  
    
    return result;
    
}
