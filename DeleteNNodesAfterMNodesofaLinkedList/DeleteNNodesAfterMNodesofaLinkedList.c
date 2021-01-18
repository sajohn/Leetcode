/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNodes(struct ListNode* head, int m, int n){
    
    if(head == NULL)
        return NULL;
    
struct ListNode *prev, *next, *front, *tmp;
int count = 0; 
    
    front = head;
    
    while(count != m && front != NULL)
    {
        while(count != m && front != NULL)
        {
            count++;
            prev = front;
            front = front->next;
        }
        count = 0; 
        while(prev && front && count != n)
        {
            count++;
            tmp = front;
           
            front = front->next;
            tmp->next = NULL;
            free(tmp);
                
        }
        
        prev->next = front;
        count = 0;
    }
    
    return head;
}
