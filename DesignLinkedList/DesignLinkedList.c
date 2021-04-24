
typedef struct {
 int size; 
 int* arr;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)calloc(1, sizeof(MyLinkedList));
    if(obj == NULL)
        return NULL; 
    
    obj->size = 0; 
    
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
  
    if(obj)
    {
        if(index >= obj->size || obj->size <=0 || index < 0)
            return -1;
        return obj->arr[index];
    }
    
    return -1; 
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
   if(obj)
    {
      obj->arr = (int*)realloc(obj->arr, (obj->size+1)*sizeof(int));
       
       if(obj->size == 0){
           obj->arr[0] = val; 
       
       }else{      
              memmove(obj->arr+1, obj->arr, (obj->size)*sizeof(int) );
              obj->arr[0] = val; 
           }
       obj->size++;
    }
    
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
   if(obj)
    {
      obj->arr = (int*)realloc(obj->arr, (obj->size+1)*sizeof(int));
      obj->arr[obj->size++] = val; 
    }
    
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
   if(obj)
    {
       if(index > obj->size || index < 0)
           return; 
       
       if(index == obj->size){
         obj->arr = (int*)realloc(obj->arr, (obj->size+1)*sizeof(int));
         obj->arr[obj->size++] = val; 
       }
       else if(index < obj->size){
           obj->arr = (int*)realloc(obj->arr, (++obj->size)*sizeof(int));
           memmove(obj->arr+index+1, obj->arr+index, (obj->size - index-1)*sizeof(int) );
           obj->arr[index] = val; 
       }
    }
    return; 
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
   if(obj)
    {
       if(index >= obj->size || index < 0 )
           return ; 
       
        if(index < obj->size && index >= 0){
            if(obj->size == 1)
            {
                free(obj->arr);
                obj->size--;
            }else{
                if(index == 0 ){
                     memmove(obj->arr+index, obj->arr+index+1, (--obj->size)*sizeof(int) );
                     obj->arr = (int*)realloc(obj->arr, (obj->size)*sizeof(int));
                    
                }else if(index == obj->size-1 ) {
                     obj->arr = (int*)realloc(obj->arr, (--obj->size)*sizeof(int));
                }else {
                    memmove(obj->arr+index, obj->arr+index+1, (obj->size - index-1)*sizeof(int) );
                    obj->arr = (int*)realloc(obj->arr, (--obj->size)*sizeof(int));
                }
           }
      }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    
    if(obj) {
        if(obj->arr!= NULL && obj->size !=0)
            free(obj->arr);
      free(obj);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
