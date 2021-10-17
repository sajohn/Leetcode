/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
 
    if(n == 0 )
        return head;
    struct ListNode dummy; 
    dummy.val = -1; 
    dummy.next = head; 
    
    struct ListNode* first=&dummy, *second = &dummy, *previous = NULL;
    int cnt = 0;
    
    while(first)
    {
        if(cnt <= n)
        {
            first = first->next; 
            cnt++; 
        }
        else{
            first = first->next; 
            second = second->next; 
        }
        
    }
  
    second->next = second->next->next; 
   
    return dummy.next;
    
}
