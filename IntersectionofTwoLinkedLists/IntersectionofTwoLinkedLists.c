typedef struct hashNode 
{
   struct ListNode *addr; 
   UT_hash_handle hh;
} hashNode; 

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if(headA == NULL || headB== NULL)
        return NULL; 

   hashNode *g_users= NULL, *element;
    
   struct ListNode *pA= headA, *pB = headB;
    
    
    while(pA != NULL)
    {
        HASH_FIND(hh, g_users, &pA, sizeof(element), element);
        
        if(element == NULL)
        {
            element = (hashNode*)calloc(1, sizeof(hashNode));
            if(element == NULL)
                return NULL; 
            
           element->addr = pA; 
          HASH_ADD(hh, g_users, addr, sizeof(element), element);  
        }
        
        pA= pA->next; 
    }
    
    while(pB != NULL)
    {
        HASH_FIND(hh, g_users, &pB, sizeof(element), element);
          
          if(element == NULL)
             pB = pB->next;  
           else
               return (struct ListNode*)pB;
     }
    
    return NULL; 
}
