/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
#define SIZE 20480
struct TreeNode* queue[SIZE] = {0};

char* serialize(struct TreeNode* root) 
{
    if(root == NULL)
        return "";

    char* ret = (char*) calloc(1024*1024, sizeof(char));
   
    if(ret== NULL)
        return NULL;
    
     if(root!= NULL && (root->left == NULL && root->right == NULL))
     {
          sprintf(ret, "%d,", root->val);
          return ret;
     }
    
    int head =0, tail = 0, idx=0; 
    
    tail = head;
    queue[tail++] = root;

    while(head<tail)
    {
        root = queue[head++];
           
        if(root!= NULL)
        {
            idx += sprintf(ret+idx, "%d,", root->val);
            queue[tail++] = root->left;
            queue[tail++] = root->right;
        }
        else
        {
           idx += sprintf(ret+idx, "null,");
           if(head == tail)
               break;
        }
        
    }

   ret[idx-1] = '\0';

  return ret;  

}

  
struct TreeNode* newNode(int data)
{
     struct TreeNode* root = (struct TreeNode* )calloc(1, sizeof(struct TreeNode));
    if(root == NULL)
        return NULL;
    root->val = data; 
    root->left = root->right = NULL;
    return root;
}

//Relying on searialized data one can simply assume that the nodes come in sequence
//i.e. first null is left second null is right othere both left right are null

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) 
{
  
    if(data == NULL)
        return NULL;
    
    struct TreeNode *root = NULL;
    int head=0, tail=0;
    char *token = strtok(data, ",");
    if(token && strcmp(token, "null") != 0) {
        root = newNode(atoi(token));
        queue[tail++] = root;
    }

    while(head<tail) {
        struct TreeNode *node = queue[head++];
        
        if(node) {
             token = strtok(NULL, ",");
 
            if(token && strcmp(token, "null") != 0){
                node->left = newNode(atoi(token));
                queue[tail++] = node->left;
            }
            token = strtok(NULL, ",");
             if(token && strcmp(token, "null") != 0){
                node->right = newNode(atoi(token));
                queue[tail++] = node->right;
            }
        }
    }
    return root;

}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);


