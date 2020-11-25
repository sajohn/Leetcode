/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head)
{
   if(!head)
       return NULL;
    
    struct ListNode* previous = NULL, *current = NULL;
    
    current = head;
    while(head)
    {
       head = head->next; 
       current->next = previous;
       previous = current;
       current = head;
    }
    
    return previous;
}

bool isPalindrome(struct ListNode* head){
    
    if(head == NULL || head->next == NULL)
        return true;
    
    
   struct ListNode *slow, *fast, *mid;
    slow = fast = head;
    
    while(fast != NULL && slow!= NULL)
    {
        fast = fast->next;
        if(fast == NULL)
        {
            mid = slow;
            break;
        }
        
        if(slow !=fast)
            fast = fast->next;
         if(fast == NULL)
        {
            mid = slow;
            break;
        }
        if(fast != NULL)
            slow = slow->next; 
        
    }
    
   fast = mid->next;
    
   fast = reverseList(fast);
    
    if(head == slow && slow->next == fast && slow->val != fast->val)
        return false;
    
    
    while( fast != NULL)
    {
       if(head->val != fast->val)
       return false;
     head= head->next;
     fast = fast->next;
    }
    
    
    return true;

}
