/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

 
struct Node* copyRandomList(struct Node* head) {

    if(head == NULL) 
        return NULL; 
    if(head && head->next == NULL){
        struct Node* node = ( struct Node* )calloc(1, sizeof( struct Node));
     node->val = head->val; 
     node->random = (head->random)?node: NULL;
     node->next = NULL; 
    return node; 
}
    
    struct Node* originalHead = head; 
     
    struct Node* dupeHead = NULL, *dupeHead1 = NULL, *tmp = NULL;
    
     while(originalHead ) {
   
        dupeHead = ( struct Node* )calloc(1, sizeof( struct Node));
        if(dupeHead == NULL)
            return NULL; 
         
     dupeHead->val = originalHead->val; 
   
     dupeHead->next = NULL;
     dupeHead->random = NULL; 

        dupeHead->next = originalHead->next; 
        originalHead->next = dupeHead;
        originalHead  = dupeHead->next;
         
    }
    
    
  originalHead = head; 
  dupeHead1 = originalHead->next; 
  dupeHead = originalHead->next; 
       
    
    while(originalHead)
    {
        dupeHead->random = (originalHead->random? originalHead->random->next: NULL); 
        originalHead = dupeHead? dupeHead->next: NULL; 
        dupeHead = originalHead?originalHead->next : NULL; 
    }
    
    originalHead = head;
    dupeHead = originalHead->next; 
    
    while(originalHead && dupeHead) {
    
       originalHead->next = dupeHead? dupeHead->next: NULL; 
       dupeHead->next =  dupeHead->next? dupeHead->next->next: NULL; 
       originalHead =   originalHead->next; 
       dupeHead = dupeHead->next ;
      }
    
    return dupeHead1; 
}
