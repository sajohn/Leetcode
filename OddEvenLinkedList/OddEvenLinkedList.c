/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void OddEven(struct ListNode** odd, struct ListNode** even, struct ListNode** tail)
{
   
        
    struct ListNode *headodd, *headeven;
    
      headodd = (*odd);
      headeven = (*even);
    if(headodd == NULL && headeven == NULL)
        return NULL;
    
     if(headeven)
       headodd->next = headeven->next;
    
     if(headeven && headeven->next )
       headeven->next = headeven->next->next;
    
    if(headeven)
        headeven = headeven->next;
    
    if(headodd)
    {
        (*tail) = headodd;
        headodd = headodd->next;
    }
 
    OddEven(&headodd, &headeven, tail);
        
}

struct ListNode* oddEvenList(struct ListNode* head)
{

    
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* even = head, *odd = head->next, *tail = head->next;
    
    OddEven(&even, &odd, &tail);
    
    tail->next = odd;
    
    return head;    
}
