typedef struct hash{
    
    int value; 
    int idx; 
    UT_hash_handle hh; 
}hash;

bool checkIfExist(int* arr, int arrSize){
    
    hash* guser = NULL, *element = NULL; 
    int val = 0, val1 = 0; 
    
    for(int i = 0; i< arrSize; i++)
    {
        val = arr[i];
     
        HASH_FIND_INT(guser, &arr[i], element);
        if(element == NULL || (element && element->idx != i && element->value != 0))
        {
            element = (hash*)calloc(1, sizeof(hash));
            element->value = arr[i];
            element->idx = i; 
            HASH_ADD_INT(guser, value, element);
        }
       
        hash* element2 = NULL; 
        val1 = 2*arr[i];
            
       HASH_FIND_INT(guser, &(val1), element2);
       if(element2 && element2->idx != i)
           return true; 
        
        if(arr[i] & 1)
            continue;
        val1 = arr[i]/2; 
         
        HASH_FIND_INT(guser, &(val1), element2);
          if(element2 && element2->idx != i)
            return true; 
    }

    return false; 
    
}
