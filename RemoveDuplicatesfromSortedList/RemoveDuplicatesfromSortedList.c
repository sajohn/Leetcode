/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL)
        return NULL;
    struct ListNode* prev, *next, *tmp;
    prev = head;
    
    if(prev->next == NULL)
        return prev;
    
    next = prev->next;
    while(prev)
    {
        if(next != NULL && prev->val == next->val )
        {
            tmp = next;
            prev->next = next->next; 
            next = next->next;
            free(tmp);
        }
        else
        {
            prev = prev->next;
            if(next)
             next = next->next;
        }
    }
    
    return head;

}
