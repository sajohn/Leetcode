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
    while(head )
    {
       head = head->next; 
       current->next = previous;
       previous = current;
       current = head;
    }
    
    return previous;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    
    if(!head)
        return NULL;
    int listlen = 0, tmpcount =1;
    struct ListNode* current = NULL, *tmp = NULL, *end= NULL, *previous= NULL, *tmpHead = NULL; 
    
    current = head;
    
    while(current)
    {
        listlen++;
        current = current->next;
    }
    
  

    if(listlen == 1)
        return head;
    
    
    if(m >listlen || n >listlen || m == n || m < 0 || n < 0 )
        return head;
    
    if(m <=1 && listlen==2)
    {
        return reverseList(head);
    }
    
    current = head;
    
    if(m < n && n <=listlen)
    {
        //starthead, head of returned list, 
      if(m ==1)
      {
        previous = current;
      }
      else
      {  
        while(current && tmpcount<m)
        {
            previous = current;
            current = current->next;
            tmpcount++;
        }
      }
        //current is now at position it needs but previous is not if m <=1
        
        tmp = current;
        
        while(tmp && tmpcount < n)
        {
            tmp = tmp->next;
            tmpcount++;
        }
       
        //tmp is no pointing to end .
        end = tmp->next;
        tmp->next = NULL;
        
      if(m!=1)
      {
        previous->next = reverseList(current);
        current = previous ->next;
      }
    else 
    {
        head = reverseList(current);
        current = head;
        previous = head;
    }
        
        while(current->next)
            current=current->next;
        
        current->next = end;
        
    }
    return head;
    
}
