/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    
    
if(head == NULL)
        return NULL;
    struct ListNode* prev, *next, *cur, *tmp;
    prev = NULL;
    cur = head;
    next = cur->next;
    
    if(cur->next == NULL)
        return cur;
    
    while(next)
    {
         if(next != NULL && cur->val != next->val )
         {
             prev = cur;
             cur = next;
             next = next->next;
         }
        if(next != NULL && cur->val == next->val )
        {
            while(next && cur->val == next->val)
             next = next->next;
       
            tmp = cur;
            if(prev && prev != cur)
              prev->next = next;
            else
            {
              head = next;
              prev = next;
              
            }
            
            while(cur && cur != next){
                cur = cur->next;
               free(tmp);
                tmp= cur;
            }
            cur = prev;
            
            if( cur == next && next )
                next = next->next;
        }
       
    }
    
    return head;

}

