/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */




#define SIZE 6000
struct Node* queue[SIZE] = {0};


struct Node* connect(struct Node* root){

       if(root==NULL) 
           return NULL;
    
    struct Node *pre = NULL, *original = NULL;
    
    
     if(root!= NULL && (root->left == NULL && root->right == NULL))
     {
         root->left = NULL; 
         root->right = NULL; 
         root->next = NULL; 
         return root; 
     }
    
    int head =0, tail = 0; 
    original = root; 
    tail = head;
    queue[head] = root;
    root->next = NULL; 
    tail++;
    queue[tail++] = NULL;
    
    while(head<tail)
    {
        root = queue[head++];
       
        if(root!= NULL) {
            
            root->next = queue[head];
             pre =  root;
             if(root->left)
                queue[tail++] = root->left;
              if(root->right)
                queue[tail++] = root->right;
        } else {
             pre->next = NULL; 
           if(head == tail) { //Because tail is always pointing to write index and this is last entry so stop
          
               break;
           } else {
               queue[tail++] = NULL;
              
            }
        }
    }

    return original;

}
