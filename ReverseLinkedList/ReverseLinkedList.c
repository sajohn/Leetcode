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
