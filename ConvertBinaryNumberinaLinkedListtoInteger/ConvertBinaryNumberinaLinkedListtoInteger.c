/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* Reverse(struct ListNode* head){
    
    if(head == NULL)
        return NULL; 
    
    struct ListNode* cur = NULL, *prev = NULL; 
    
    cur = head; 
    
    while(cur)
    {
        head = head->next; 
        cur->next = prev; 
        prev = cur; 
        cur = head; 
    }
    
    return prev;
}


int getDecimalValue(struct ListNode* head){
    
   head =  Reverse(head);
    int answer = 0, index = 0; 
    while(head != NULL)
    {
        if(head->val == 1)
            answer += pow(2, index);
         index++; 
         head = head->next; 
    }
    
return answer; 
}
