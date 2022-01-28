typedef struct Hash{
    int key; 
    int val; 
    UT_hash_handle hh; 
}Hash; 



//After sum %k we get a number and if that number is same that mean we has 

bool checkSubarraySum(int* nums, int numsSize, int k){
    Hash* guser = NULL, *element; 
    
    if(nums == NULL || numsSize == 0)
        return false; 
    int sum = 0, left=0, right =0;
    
     element = (Hash*)calloc(1, sizeof(Hash));
                if(element == NULL)
                    return false; 
                element->key = 0; 
                element->val = -1;
    HASH_ADD_INT(guser, key, element );
    
    for(int i =0; i < numsSize; i++)
    {
        sum+=nums[i];
        sum %=k; 
        
        HASH_FIND_INT(guser, &sum, element);
        if(element && i-element->val > 1)
               return true;
        else if( i>0 && (nums[i-1] + nums[i]) %k == 0) return true; //This is covering case of 0 itself 
        else{
                element = (Hash*)calloc(1, sizeof(Hash));
                if(element == NULL)
                    return false; 
                element->key = sum; 
                element->val = i;

                HASH_ADD_INT(guser, key, element );
            }
    }
    
    return false; 
}
