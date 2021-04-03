struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if(headA == NULL || headB== NULL)
        return NULL; 
   
    struct ListNode *pB = headB;
    
    while(headA != NULL ) {
        
        pB = headB; 
        
        while(pB != NULL )
        {

            if(headA == pB)
                return headA; 
            pB = pB->next;
        }
     headA=headA->next;
    }
   return NULL; 
}
