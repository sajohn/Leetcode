

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool verifyPreorder(int* preorder, int preorderSize){
    
    //find next greater element in array than root (which is a first element)
    //ascending after first > root element
    
    
    if(preorder == NULL || preorderSize == 0)
        return false; 
    
    if(preorderSize == 1)
        return true; 
    
  int root = INT_MIN, stack[preorderSize], top = -1;
  
  memset(&stack, 0, sizeof(int)*preorderSize);
    
 for(int i =0; i < preorderSize; i++)  { 
 
     while(top != -1 && stack[top] < preorder[i] ){
     
         root = stack[top--]; //This is popping untill stack is empty or volation is hit
         //stack[top--] = INT_MIN ;
         

     }
    if(preorder[i] < root)
          return false;
     
     stack[++top]=preorder[i];
     
 }
    return true; 
}
