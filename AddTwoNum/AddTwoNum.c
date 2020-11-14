/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int val =0, carry =0; 
    
    struct ListNode* head = NULL, * h = NULL, *head1=NULL, *head2=NULL, *prev = NULL, *final = NULL;
    
    if(l1 == NULL && l2 == NULL)
        return NULL;
    
   if (l1 != NULL && l2 == NULL)
     return l1;

   if (l2 != NULL && l1 == NULL)
     return l2;
  
    
      head = (  struct ListNode*)malloc(sizeof(  struct ListNode));
       if(!head)
           return NULL;
    
    head1 = l1;
    head2 = l2;
    
    while(head1 && head2)
    {
       head1 = head1->next;
       head2 = head2->next;
    }
     if(head1 == NULL && head2 == NULL)
         h = l1;
     else if(head1 == NULL && head2 != NULL)
         h = l2;
     else if(head1 != NULL && head2 == NULL)
         h = l1;
    
    head1 = l1;
    head2 = l2;
    
    final = h;
    
    while(h)
    {
        if(head1 && head2)
        {
          val = (carry+ head1->val + head2->val)%10;
          carry = (carry+head1->val + head2->val)/10;
            
          h->val = val;
          prev = h; 
          head1 = head1->next;
          head2 = head2->next;
         
        }
        else
        {
           val = (carry + h->val)%10;
            
            carry = (carry + h->val)/10;
            h->val = val;
            prev = h;
        }
           h = h->next;
    }
    
 if(carry>0 && h == NULL)
 {
     prev->next = (struct ListNode* )malloc(sizeof(struct ListNode));
     prev->next->val = carry;
     prev->next->next = NULL;
 }
   
    return final;
}
