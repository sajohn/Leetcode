
/*
Head and Tail for DLL are dummy...
I have created two structures one for Doublly link list(Dll) and another for simple traversing which doens't have any HASH functionality. 

LRU node is pushed to Dll and and is also reflected with 

*/

typedef struct LRUNode{
    int key; 
    int val; 
    struct LRUNode* next; 
    struct LRUNode* prev; 
    UT_hash_handle hh; 
} LRUNode;
   
typedef struct LRUCache{
    int size; 
    int capacity; 
    struct LRUNode* head; 
    struct LRUNode* tail; 
       
    struct LRUNode** guser; 
   
}LRUCache;


void addNode(LRUCache* obj, LRUNode* node)
{
     if(node == NULL || obj == NULL)
        return; 
    
   node->prev = obj->head; 
   node->next = obj->head->next; 
   obj->head->next->prev = node; 
   obj->head->next = node; 
}

void RemoveNode(LRUNode* node){
   if(node == NULL)
        return; 
    
    struct LRUNode* next  = node->next; 
    struct LRUNode* prev  = node->prev; 
    
    prev->next = next; 
    next->prev = prev; 
}

LRUNode* RemoveTail(LRUCache* obj)
{
     
    LRUNode* node;
    int key =  obj->tail->prev->key; 
    HASH_FIND_INT(*(obj->guser),&key, node); 
    
    if(node == NULL)
        return NULL; 
    RemoveNode(node);
    return node; 
}

void moveToFront(LRUCache* obj, LRUNode* node)
{
    if(obj == NULL || node == NULL)
        return; 
    
   RemoveNode(node);
   addNode(obj, node); 
    
}

LRUCache* lRUCacheCreate(int capacity) {
    
    if(capacity < 0 )
        return NULL; 
    static LRUNode* guser = NULL;  
    
    LRUCache* node = (LRUCache*) calloc(1, sizeof(LRUCache));
    if(node == NULL)
        return NULL; 
    
    node->capacity = capacity; 
    node->size = 0; 
    node->guser = (LRUNode**)&guser; 

     LRUNode* head = (LRUNode*) calloc(1, sizeof(LRUNode));
     LRUNode* tail = (LRUNode*) calloc(1, sizeof(LRUNode));
    if(head == NULL || tail == NULL)
        return NULL; 
    head->next = tail; 
    tail->prev = head; 
    node->head = head; 
    node->tail = tail; 
    
    return node; 
}


int lRUCacheGet(LRUCache* obj, int key) {
  
    LRUNode* element; 
    if(obj == NULL)
        return -1; 
    if(obj->size == 0)
        return -1; 

    HASH_FIND_INT(*(obj->guser), &key, element); 
    if(element == NULL)
        return -1; 
    
    moveToFront(obj, element);
    return element->val; 
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  
    if(obj== NULL)
        return; 
  
    LRUNode* element = NULL; 
    
    HASH_FIND_INT(*(obj->guser), &key, element); 
    if(element == NULL)
    {
       element= ( LRUNode*)calloc(1, sizeof(LRUNode));
        if(element == NULL)
            return; 
        
        element->key = key; 
        element->val = value; 
        
        HASH_ADD_INT(*(obj->guser), key, element);
        addNode(obj, element);
        obj->size++; 
      
        if( HASH_COUNT(*(obj->guser)) > obj->capacity)
        { 
            LRUNode* tail = RemoveTail(obj);
            obj->size--; 
            HASH_DEL(*(obj->guser), tail); 
            free(tail);
        }
        
    } 
    else{
        element->val = value; 
        moveToFront(obj, element);
    }
    
    
}

void lRUCacheFree(LRUCache* obj) {
    
    if(obj == NULL)
        return ;
    struct LRUNode *current_user, *tmp;

    HASH_ITER(hh, *(obj->guser), current_user, tmp) {
    HASH_DEL( *(obj->guser), current_user);  
    free(current_user);            
  }
    
    free(obj);
    
}

