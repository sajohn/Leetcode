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
void Reverse(struct ListNode** head, struct ListNode** tail)
{
   if(head == NULL || tail == NULL) 
       return;
    
    struct ListNode *start, *end ;
    if(*tail) 
        end= (*tail);
    if(*head)
        start = (*head);

if(*tail)   
    (*tail)->next = NULL;
    
    (*head) = reverseList(*head);
    
     (*tail) = start;    
    
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    
    
    if(head == NULL )
        return NULL;
    if(k <= 0)
        return head;
    int count = 0; 
    
    struct ListNode* tmp, *prev, *next;
    tmp = head;
    
    while(count != k && tmp )
    {
        count++; 
        prev = tmp;
        tmp = tmp->next;    
    }
    
    if(count < k)
        return head;
    
    Reverse(&head, &prev);
    
    prev->next = reverseKGroup(tmp, k);
    
    return head;

