
typedef struct  {
  int value;
  int idx; 
  UT_hash_handle hh;
}number_set;

int maxOperations(int* nums, int numsSize, int k){
    
    
if(!nums || numsSize <2 )
         return -1;

   number_set* set = NULL;
   number_set* element;
 
 int count = 0; 
    
  for (int i = 0; i < numsSize; ++i) 
  {
      int tmp = k - nums[i];
      
      HASH_FIND_INT(set, &tmp, element);
      if(element)
      {
        count++; 
          //Don't add current element nums[i]
          //Remove complement
        HASH_DEL(set, element);  
          
      }
      else{
          
          element = (number_set*)calloc(1, sizeof(number_set));
          if(element == NULL)
              return -1; 
          
          element->value = nums[i];
          element->idx = i; 
          HASH_ADD_INT(set, value,element );
      }
  }
    
return count; 
}
