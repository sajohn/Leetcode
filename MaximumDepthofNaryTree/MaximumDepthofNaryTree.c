/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
int  Max(int depth, int val)
{
    return (depth > val? depth:val);
}

int FindMaximumDepth(struct Node* root) 
{
     if(root == NULL)
         return 0;
    
    if(root && root->numChildren == 0 || root->children == NULL)
        return 1; 
    int depth = 0, val =0;
    
    for(int i =0; i < root->numChildren; i++)
    {
        val = 1+ FindMaximumDepth(root->children[i]);
        depth = Max(depth, val);
    }
    
    return depth;
}

int maxDepth(struct Node* root) 
{
     if(root == NULL)
         return 0;
    
    if(root && root->numChildren == 0 || root->children == NULL)
        return 1; 
    
    
    return FindMaximumDepth(root);
    
}
