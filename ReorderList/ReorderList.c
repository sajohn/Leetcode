/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* FindMid(struct ListNode* head)
{
    if(head == NULL)
        return head; 

    struct ListNode* slow, *fast; 
    slow = fast = head;
 
    while(fast->next != NULL)
    {
        fast = fast->next; 
        if(fast == NULL)
            return slow; 
        
        if(fast->next != NULL) {
            slow = slow->next; 
            fast = fast->next; 
        } else {
            break;
        }
    }
    return slow; 
}

struct ListNode* Reverse(struct ListNode* head) {
    
    if(head == NULL)
        return NULL; 
    
    struct ListNode* cur, *prev = NULL; 
    
    cur = head; 
    
    while(cur)
    {
       head= head->next; 
        cur->next = prev; 
        prev = cur; 
        cur = head; 
    }
    
    return prev; 
}


void reorderList(struct ListNode* head){
    
    
    if(head == NULL)
        return ; 
    
    struct ListNode* first, *second, *tmp1, *tmp2; 
    
    
    first = head; 
    
    second = FindMid(first);
    
    second = Reverse(second);
    
    
    while(first && second)
    {
        tmp1 = first->next; 
        first->next = second; 
        tmp2 = second->next; 
        second->next = tmp1; 
        first = tmp1; 
        second = tmp2; 
    }
    

    return head; 
    

}
