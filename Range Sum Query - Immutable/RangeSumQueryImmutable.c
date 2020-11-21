


typedef struct {
  int* numarr;
  int idx;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return NULL;
    
    NumArray* num = (NumArray*)calloc(1, sizeof(NumArray));
    if(num == NULL)
        return NULL;
    num->idx = numsSize;
    num->numarr = (int*)calloc(numsSize+1, sizeof(int));
    if(num->numarr == NULL)
        return NULL;
    
    num->numarr[0] = nums[0];
    
    for(int i =0; i <numsSize; i++)
        num->numarr[i+1] =num->numarr[i]+nums[i];
        
    return num;
}

int numArraySumRange(NumArray* obj, int i, int j) {
  if(obj == NULL || i<0 || j<0 || i > obj->idx || j>obj->idx)
      return INT_MIN;

        return obj->numarr[j+1] - obj->numarr[i];
    
}

void numArrayFree(NumArray* obj) {
    if(obj)
        free(obj->numarr);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
