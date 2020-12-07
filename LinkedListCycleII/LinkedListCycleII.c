/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{

    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;
    
    struct ListNode *slow, *fast;
    int count = 0;
    
    slow = fast = head;
  
    do
    { 
        slow = slow->next; 
     if(fast)
        fast = fast->next;
      if(fast)
            fast = fast->next; 
      
    } while(fast != slow );   
    
    slow = head;
    
    while(slow !=fast)
    {
        slow = slow->next;
        if(fast)
        fast = fast->next;
    }

  return slow;
}
