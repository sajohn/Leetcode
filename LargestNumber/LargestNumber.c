int cmp(void* a, void* b)
{
    long long aa = *(int*)a;
    long long bb = *(int*)b;

    
     char s1[50] = {0};
     char s2[50] = {0};
     char s3[50] = {0};
    // Convert both the integers to string
    sprintf(s1, "%llu", aa);
    sprintf(s2, "%llu", bb);
    sprintf(s3, "%llu", aa);
 
    // Concatenate both strings
    strcat(s1, s2);
    strcat(s2, s3);

  // printf("%s  %s %llu %llu ",s1, s2, atol(s1), atol(s2));
    
    aa = atol(s1);
    bb = atol(s2);
    
    if(aa> bb)
        return -1; 
    else if(aa < bb)
        return 1; 
    else 
        return 0; 
}
/*
a = 9 b = 5 c = 1
ab > ba 
a comes first then b

b c a

bc > cb

ac > ca

*/
char * largestNumber(int* nums, int numsSize){

    if(nums == NULL || numsSize == 0)
        return 0; 
    
  char tmp [30]= {0}; 
  int count = 0;
  char* ret = (char*)calloc(900, sizeof(char));
   if(ret == NULL)
       return NULL; 
    
    for(int i =0; i < numsSize; i++){
        if(nums[i] == 0) 
            count++; 
        if(count == numsSize)
            return "0";
    }
   qsort(nums, numsSize, sizeof(int), cmp);
   
    for(int i =0; i < numsSize; i++){
        sprintf(tmp, "%d", nums[i]);
        strcat(ret, tmp);
    }
        
    return ret; 
    
}
