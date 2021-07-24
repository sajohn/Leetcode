/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };

///The idea is to have thee nodes at a time. 
(At begening the start will be with dummy node)

res --->
        \ -->cur
                \-->next

 */
struct ListNode* insertionSortList(struct ListNode* head){
    
    if(head == NULL)
        return NULL; 

    struct ListNode* res;
    struct ListNode dummy;
    res = &dummy;
    res->next=head;
    int done=0;
    while (!done){
        struct ListNode *prev=res,*cur=res->next,*next=res->next->next;
        done=1;
        while (next){
            if(next->val<cur->val){
               prev->next=next;
                cur->next=next->next;
                next->next=cur;
                done=0;
            }
            prev=cur;
            cur=next;
            next=next->next;
        }
    }
    return res->next;
    

}
