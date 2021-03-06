

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int maxofThree(int *a, int* b, int*c)
{
    int max =0; 
    if(*a>*b)
        max = *a;
    else
        max = *b;
    
    if(*c>max)
        max = *c;
    
    return max;
}

int* arraysIntersection(int* arr1, int arr1Size, int* arr2, int arr2Size, int* arr3, int arr3Size, int* returnSize)
{

    if(arr1 == NULL || arr1Size==0 || arr2==NULL || arr2Size == 0|| arr3 == NULL || arr3Size == NULL)
        return NULL;
    
    int* res = (int*)calloc(2000, sizeof(int));
    if(res == NULL)
        return NULL;
    
    int i =0, j=0, k =0, l =0;
    
    while(i< arr1Size && j< arr2Size && k< arr3Size)
    {
       if(arr1[i]< maxofThree(&arr1[i], &arr2[j], &arr3[k]))
            i++;
        else if(arr2[j]< maxofThree(&arr1[i], &arr2[j], &arr3[k]))
            j++;
        else if(arr3[k]< maxofThree(&arr1[i], &arr2[j], &arr3[k]))
            k++;
        else{
           res[l++] = arr1[i++];
            j++; k++;
        }       
    
    }
    
    *returnSize = l;
    res = (int*) realloc(res, (l)*sizeof(int));
    
    return res;
   
}



