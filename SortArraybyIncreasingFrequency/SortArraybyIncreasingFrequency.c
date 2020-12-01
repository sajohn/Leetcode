

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct number_set {
  int value;
  int freq; 
  UT_hash_handle hh;
};

int cmpFunc(struct number_set *a, struct number_set *b)
{
    if(a->freq < b->freq)
        return -1;
    else if(a->freq > b->freq )
        return 1;
    else if(a->freq == b->freq )
    {
        if(a->value > b->value)
            return -1;
        else if(a->value < b->value)
            return 1;
        else
         return 0;
    }
    return -1;
}


int* frequencySort(int* nums, int numsSize, int* returnSize)
{
    if(nums == NULL || numsSize ==0)
        return NULL;
    int i =0;
    *returnSize =0;
    
     struct number_set* set = NULL;
     struct number_set* element;

    
     for (int i = 0; i < numsSize; ++i) 
     {
        HASH_FIND_INT(set, &nums[i], element);
        if (element) {
            element->freq++;
        }
       else{
        element = (struct number_set *) malloc(sizeof(*element));
        element->value = nums[i];
        element->freq = 1;
        HASH_ADD_INT(set, value, element);
       }
  }
 
   HASH_SORT(set, cmpFunc);
           
  /* Destroy the hashset */
  struct number_set* curr;
     
 *returnSize = numsSize;
  int* ret = (int*)calloc(numsSize, sizeof(int));
    if(ret == NULL)
        return NULL;
    
  HASH_ITER(hh, set, curr, element) {
         while(curr->freq){
         ret[i++] = curr->value;
          curr->freq--;
    }
    HASH_DEL(set, curr);
    free(curr);
  }
  
  return ret;  
}
