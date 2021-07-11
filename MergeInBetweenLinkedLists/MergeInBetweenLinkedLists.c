/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* l1, int a, int b, struct ListNode* l2){
    
    if(a <0 || b < 0 || (a>b))
        return NULL; 
    
    if(l1 == NULL)
        return l2; 
     struct ListNode* l1a = l1, *l1b, *preva, *prevb; 
    
    int edge1 = 0, edge2 = 0;
    
    while(edge1 != a || edge2 != b){
        
        if(edge1 != a){
            preva = l1a;
         l1a = l1a->next; 
         l1b = l1a; 
            edge1++;
            edge2 = edge1;
        }
    
        if(edge1 == a && edge2 != b){
            prevb = l1b;
            l1b = l1b->next; 
            edge2++;
        }
            
    }
    
    if(l2 == NULL)
    {
        preva->next = prevb->next; 
        prevb->next = NULL; 
        
        return l1; 
    }
    else{
        preva->next = l2;
        struct ListNode* l2l= l2;  
    
    while(l2l->next != NULL){
        l2l = l2l->next; 
    }
        l2l->next = l1b->next; 
        l1b->next = NULL; 
        return l1; 
    }
    
           
return NULL; 
}
