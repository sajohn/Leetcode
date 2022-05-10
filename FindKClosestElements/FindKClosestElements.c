

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    
    *returnSize = 0; 
    
    
    if(arr == NULL || arrSize == 0 || k == 0 )
        return NULL; 

    int l=0, r = arrSize-1, mid=0, d1=0, d2=0, count=0;
    int* ret = (int*)calloc(k, sizeof(int));
    if(ret == NULL)
        return NULL; 
    
    while(l<r && (r-l+1>k)){
       
        d1 = abs(arr[l] - x);
        d2 = abs(arr[r] - x);
        
         if(d1 > d2 )
            l++; 
        else if(d1<d2)
            r--; 
        else{
            if( arr[l] < arr[r])
                r--; 
            else
                l++;
        }
    
    }
      *returnSize = k; 
    memcpy(ret, &arr[l], sizeof(int)* k);
    
    return ret; 
}


