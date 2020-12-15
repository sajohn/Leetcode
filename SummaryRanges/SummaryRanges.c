#define MAX_SIZE 35

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize)
{
    *returnSize =0; 
    if(nums == NULL || numsSize ==0)
        return "";
  
    char ss[MAX_SIZE] = {0};
    char**str; 
    
    str = (char*)calloc(numsSize, sizeof(char*));
    if(str == NULL)
        return NULL;
    
    
    if(numsSize ==1)
    {
          *returnSize =1; 
          
          str[0] = (char*)calloc(MAX_SIZE, sizeof(char));
          snprintf(ss, MAX_SIZE, "%d", nums[0]);
           strncpy(str[0], ss, strlen(ss)+1);
          return str;
    }
    
    
    int pre = nums[0], j =0, i =0;
    
    for( i =0; i < numsSize; i++)
    {
            
        if(i>0 && (long)nums[i]-(long)nums[i-1]>1 && i-1 != 0)
        { 
            if(pre !=nums[i-1])
            {
               snprintf(ss,MAX_SIZE, "%d->%d", pre, nums[i-1]);
               str[j] = (char*)calloc(strlen(ss)+1, sizeof(char));
               strncpy(str[j++], ss, strlen(ss)+1);
              
            }
            else 
            {
                snprintf(ss, MAX_SIZE, "%d", nums[i-1]);
                str[j] = (char*)calloc(strlen(ss)+1, sizeof(char));
                strncpy(str[j++], ss, strlen(ss));

             
            }
               pre = nums[i];
        
        }
        if(i==0 && (long)nums[i+1]-(long)nums[i]>1 && i+1<= numsSize-1)
        {
            snprintf(ss,MAX_SIZE, "%d", nums[i]);
            str[j] = (char*)calloc(strlen(ss)+1, sizeof(char));
            strncpy(str[j++], ss, strlen(ss)+1);
            pre = nums[i+1];
            
        }
    }
    if(i == numsSize )
    {
        if(pre == nums[i-1] )
        {

            snprintf(ss, MAX_SIZE, "%d", nums[i-1]);
            str[j] = (char*)calloc(strlen(ss)+1, sizeof(char));
            strncpy(str[j++], ss, strlen(ss));
         
        }
        else
        {
             snprintf(ss,MAX_SIZE, "%d->%d", pre, nums[i-1]);
               str[j] = (char*)calloc(strlen(ss)+1, sizeof(char));
               strncpy(str[j++], ss, strlen(ss)+1);
             
        }
    }
    (*returnSize) = j;
    return str;
    
}
