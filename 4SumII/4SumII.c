



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//Approach is two sum + set 


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Like java solution we need to define find 

struct hashNode {
    int sum;
    int count;
    UT_hash_handle hh;
};

struct hashNode *findUser(struct hashNode **g_users, int sum) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &sum, s);
    return s;
}

void AddUser(struct hashNode **g_users, int val1, int val2) {
    struct hashNode *s;
    
    int cursum = val1+val2; 
    
    HASH_FIND_INT(*g_users, &cursum, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)malloc(sizeof(struct hashNode));
        s->sum = val1+val2;
        s->count = 1; 
         HASH_ADD_INT(*g_users, sum, s);
    } 
    else
    {
        s->count++;
    }
    
}
int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){

 
    struct hashNode *g_users = NULL, *element;
    
    int sum = 0, cnt = 0, max = 0;
    g_users = NULL;
    
   
    if(A == NULL || ASize ==0|| B == NULL || BSize ==0|| C == NULL || CSize ==0|| D == NULL || DSize ==0)
        return 0;
  
                                                         
    //The first 0 is added to cover the case of target == sum == nums[i] (i)
    //AddUser(&g_users,0, 0);
    //Not needed here since 0 is the sum needed
    
    for (int i = 0; i < ASize; i++) 
    {
      sum = 0; 
      for (int j = 0; j < BSize; j++) { 
          
         sum = A[i]+B[j];
         AddUser(&g_users, A[i],B[j]);
      }
    }
        
     for (int i = 0; i < CSize; i++) 
    {
      sum = 0; 
      for (int j = 0; j < DSize; j++) {     
         sum = (C[i]+D[j]);
            if (element = findUser(&g_users, -sum )) {
              max+=element->count;
         }
      }
     }
    
        struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
    HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
    
    return max;
}




