/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    int size; 
    int* arr; 
    
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    
    if(head == NULL)
        return NULL; 
    
    Solution* obj = (Solution*)calloc(1, sizeof(Solution));
    if(obj == NULL)
        return NULL; 
    int count = 0; 
    while(head != NULL)
    {
        count++; 
       obj->arr = (int*)realloc(obj->arr, count*sizeof(int));
        if(obj->arr == NULL)
            return NULL; 
        
       obj->arr[count-1] = head->val; 
       head = head->next; 
        
    }
    obj->size = count; 
    
    srand(time(0));
    
    return obj; 
}

int solutionGetRandom(Solution* obj) {
    
    if(obj == NULL)
        return -1; 
    
    int idx = rand() % obj->size; 
    
    return obj->arr[idx];
  
}

void solutionFree(Solution* obj) {
    
    if(obj)
      free(obj->arr);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
