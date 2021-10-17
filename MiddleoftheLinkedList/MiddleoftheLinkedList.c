/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    
    if(head == NULL)
        return NULL; 
    
    struct ListNode* fast =head,  *slow = head; 
    
    while(fast && fast->next != NULL)
    {
        fast = fast->next; 
        
        if(fast){
            fast = fast->next; 
            if(fast)
                slow = slow->next; 
        }
    }
    
    if(fast == NULL)
        return slow->next; 
    
    else{
        return slow; 
    }
    
return NULL; 
}
