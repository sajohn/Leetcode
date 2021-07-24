/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* Helper(struct ListNode* head, int* count){
    
    if(head == NULL)
        return NULL; 
    
   struct ListNode* prev = head; 
    struct ListNode* tmp =  Helper(head->next, count);
    
    if(tmp == NULL)
    {
        int tmp = prev->val; 
        prev->val= (tmp+1) %10; 
        *count = (tmp +1 )/10; 
    }else{
          int tmp = prev->val; 
        prev->val= (tmp+*count) %10; 
        *count = (tmp +*count )/10; 
    }
    
   return head; 
}

struct ListNode* plusOne(struct ListNode* head){
    
    if(head == NULL)
        return NULL; 
    int count = 0; 
    struct ListNode* tmp = Helper(head, &count);
    
    if(count >0)
    {
        struct ListNode* ret = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        if(ret == NULL)
            return NULL; 
        ret->val = count; 
        ret->next = head; 
        head = ret; 
        return ret; 
    }
    else 
        return head; 
    
return NULL; 
}
