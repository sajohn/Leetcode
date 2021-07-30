


typedef struct TwoSum {
    int val;
    int freq; 
    struct TwoSum** guser; 
    UT_hash_handle hh; 
} TwoSum;

/** Initialize your data structure here. */
    TwoSum* guser = NULL; 
TwoSum* twoSumCreate() {
    
    TwoSum* obj = (TwoSum*)calloc(1, sizeof(TwoSum));
    if(obj == NULL)
        return NULL; 

    obj->guser = &guser; 
    return obj; 
}

/** Add the number to an internal data structure.. */
void twoSumAdd(TwoSum* obj, int number) {
  
    if(obj == NULL)
        return ; 
    TwoSum* element; 
    HASH_FIND_INT(*(obj->guser), &number, element); 
    if(element == NULL)
    {
        element = (TwoSum*)calloc(1, sizeof(TwoSum));
        if(element == NULL)
            return; 
        element->val = number; 
        element->guser = obj->guser; 
        element->freq = 1;
        
        HASH_ADD_INT(*(obj->guser), val, element);
    }
    else{
        element->freq++; 
    }
}

/** Find if there exists any pair of numbers which sum is equal to the value. */
bool twoSumFind(TwoSum* obj, int value) {
    if(obj == NULL)
        return false; 
      /* Destroy the hashset */
   TwoSum* curr;
   TwoSum* tmp;
   TwoSum* element; 
   HASH_ITER(hh, *(obj->guser), curr, tmp) {

      if(curr!= NULL)
      {
          long tmpvar = ((long)value - (long)curr->val); 
          HASH_FIND_INT(*(obj->guser), &tmpvar, element); 
          if(element)
          {
              if(element->val == value/2 && element->freq >=2)
                  return true; 
              else  if(element->val == value/2 && element->freq ==1)
                continue; 
              
             else return true;  
             
          }
      }
      
  }

return false; 
    
}

void twoSumFree(TwoSum* obj) {
    if(obj == NULL)
        return; 
    free(obj);
    guser = NULL; 
}

/**
 * Your TwoSum struct will be instantiated and called as such:
 * TwoSum* obj = twoSumCreate();
 * twoSumAdd(obj, number);
 
 * bool param_2 = twoSumFind(obj, value);
 
 * twoSumFree(obj);
*/
