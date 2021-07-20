/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* MergeLists(struct ListNode* l1, struct ListNode* l2)
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
        if(l1->val >= l2->val) {
            if(ret == NULL) {
              ret = l2;
              head = l2;
            } else {   
                if(l2 && ret)
                {
                    ret->next = l2; 
                    ret = ret->next;
                }
            }
            
            l2 = l2->next;
            
        } else {
            if(ret == NULL) {
                 ret = l1;
                 head = l1;
            } else {
               if(l1 && ret)
               {
                 ret->next = l1;
                 ret = ret->next;
               }
            }
            
            l1 = l1->next; 
        }
    }
    
    while(l1) {
        ret->next = l1;
        ret= ret->next;
        l1 = l1->next;
    }
    
    while(l2) {
        ret->next = l2;
        ret = ret->next;
        l2 = l2->next;
    }
    
    return head;
}


struct ListNode* Split(struct ListNode* head)
{
    if(head == NULL )
        return NULL; 
    
    struct ListNode* slow, *fast, *prev;
    prev = slow = fast = head; 
    
    while(fast && fast->next != NULL) {
        fast = fast->next->next; 
        prev = slow; 
        slow = slow->next; 
    }
    
    prev->next = NULL; 
   
    return slow; 
}
struct ListNode* sortHelper(struct ListNode* head)
{
        if(head == NULL)
            return NULL; 
    
    struct ListNode* first, *second; 
    
    first = head; 
    second = Split(head);
    if(first != second){
        first = sortHelper(first);
        second = sortHelper(second);
        return MergeLists(first, second);
    }
    
    return first; 
    
}
struct ListNode* sortList(struct ListNode* head)
{
        
    if(head == NULL )
        return head;
    
   return sortHelper(head); 
}
