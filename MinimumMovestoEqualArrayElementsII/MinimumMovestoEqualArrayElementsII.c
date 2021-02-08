//Let numbers becom k finally
//So in a sorted order if a number is < K it would need K-num moves to become K
//So in a sorted order if a number is > K it would need num-K moves to become K

int compare(const void* a , const void* b)
{
    return (*(int*)a) - (*(int*)b);
}

int minMoves2(int* nums, int numsSize){
    
    if(nums == NULL || numsSize == 0)
        return 0;

    
    qsort(nums, numsSize, sizeof(int), compare);
    int l =0, r = numsSize -1, move =0; 
    
    while(l<r)
        move += (nums[r--]- nums[l++]);
    
    
    
    
return move; 
}
