/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head,  struct ListNode** prev){
    
    if(head == NULL)
        return NULL; 
    
    struct ListNode* fast =head,  *slow = head; 
    *prev = slow; 
    
    while(fast && fast->next != NULL)
    {
        fast = fast->next; 
        
        if(fast){
            fast = fast->next; 
            if(fast){
                *prev = slow; 
                slow = slow->next; 
            }
        }
    }
    
    if(fast == NULL) //This is the condition for even number of nodes in link list
    {
        *prev = slow; 
        return slow->next;
    }
    
    else{
        return slow; //If odd simply return odd
    }
    
return NULL; 
}
struct ListNode* deleteMiddle(struct ListNode* head){
    
    if(head == NULL || head->next == NULL)
        return NULL; 
    
    struct ListNode* prev;
    
    struct ListNode* mid = middleNode(head, &prev );
    
    
    if(mid)
    {
        prev->next = mid->next; 
        mid->next = NULL; 
        free(mid);
        mid = NULL; 
    }
return head; 
}
