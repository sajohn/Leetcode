

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    
    *returnSize =0;
    
     char** ret = calloc(n, sizeof(char*));
        
        for(int i = 1; i <= n; i++)
        {
            if(i%3 == 0 && i%5==0)
            {
                 ret[i-1] = (char*)calloc(9, sizeof(char));
                 sprintf(ret[i-1], "FizzBuzz", 8);
            }
            else if(i%5 == 0)
            {
                 ret[i-1] = (char*)calloc(5, sizeof(char));
                 sprintf(ret[i-1], "Buzz", 4);
            }
              else  if(i%3 == 0)
            {
                 ret[i-1] = (char*)calloc(5, sizeof(char));
                 strncpy(ret[i-1] , "Fizz", 4);
            }
            else
            {
               ret[i-1] = (char*)calloc(10, sizeof(char));
                 sprintf(ret[i-1], "%d", i);
            }
       
        }
        *returnSize =n;
        return ret;
     }
 

