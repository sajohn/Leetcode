struct numberSet
{
   int val;
    UT_hash_handle hh;
};



int findDuplicate(int* nums, int numsSize)
{
   if(nums == NULL || numsSize <=0)
       return -1;

    struct numberSet* guser= NULL, *element;
    
    for(int i =0; i < numsSize; i++)
    {
        
         HASH_FIND_INT(guser, &nums[i], element);
        if(element)
           return nums[i];
        else
        {
            element = (struct numberSet*)calloc(1, sizeof(*element));
            if(element == NULL)
                return -1;
            
            element->val = nums[i];
       
            HASH_ADD_INT(guser, val, element);
        }
     }
        


 struct numberSet *current_user;

  HASH_ITER(hh, guser, current_user, element) {
    HASH_DEL(guser, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }

return -1;

}
