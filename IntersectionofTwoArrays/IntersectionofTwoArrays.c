

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

///I tried simple hashmap but timlimit exceeeded

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(int* a , int* b)
{
  int va = *(const int*) a;
  int vb = *(const int*) b;
  return (va > vb) - (va < vb);
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    if(nums1 == NULL || nums2 == NULL || nums1Size==0 || nums2Size==0 )
    {
        *returnSize =0; 
        return NULL;
    }
  int i =0, j =0, k=0; 
    
    
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
 
    
    while(i< nums1Size && j< nums2Size)
    {
        if(nums1[i]< nums2[j])
            ++i;
        else if(nums1[i]>nums2[j])
            ++j;
        else
        {
        
          if(k>0 && nums1[k-1] == nums1[i])
           {
                    i++;
                    ++j;
            }
            else
            {
              nums1[k++] = nums1[i++];
              ++j;
            }
        }       
    
    }
    
    *returnSize = k;
    nums1 = (int*) realloc(nums1, k*sizeof(int));
    
    return nums1;
   
}


