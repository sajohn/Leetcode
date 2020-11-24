/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
      if(l1 == NULL && l2 == NULL)
          return NULL;
      if(l1 == NULL)
          return l2;
        if(l2 == NULL)
          return l1;
    
    struct ListNode* head, *ret=NULL;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val >= l2->val)
        {
            if(ret == NULL)
            {
              ret = l2;
              head = l2;
            }
            else 
            {   
                if(l2 && ret)
                {
                    ret->next = l2;
                     
                    ret = ret->next;
                }
            }
            
            l2 = l2->next;
            
        }
        else
        {
            
            if(ret == NULL)
            {
                 ret = l1;
                 head = l1;
            }
            else 
            {
               if(l1 && ret)
               {
                 ret->next = l1;
                 ret = ret->next;
               }
            }
            
            l1 = l1->next; 
        }
    }
    
    while(l1)
    {
        ret->next = l1;
        ret= ret->next;
        l1 = l1->next;
    }
    
     while(l2)
    {
        ret->next = l2;
        ret = ret->next;
        l2 = l2->next;
    }
    
    return head;
}
