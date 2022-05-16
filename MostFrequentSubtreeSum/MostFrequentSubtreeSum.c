/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int sum; 
    int freq;
    UT_hash_handle hh; 
} Hash; 


int cumfunc(Hash* h1, Hash* h2){
    
    return h2->freq - h1->freq; 
}


int Sum(struct TreeNode* root, Hash** guser) {
    
    //Check sum at everystage and maintain count; 
    
    if(root == NULL)
        return 0; 
    

  Hash* element = NULL; 
  int sum = root->val + Sum(root->left, guser) + Sum(root->right, guser);
    
   HASH_FIND_INT(*guser, &sum, element);
    if(element == NULL)
    {
        element= calloc(1, sizeof(Hash));
        if(element == NULL)
            return INT_MAX; 
        
        element->sum = sum; 
        element->freq = 1; 
        
        HASH_ADD_INT(*guser, sum, element);
    }
    else{
        element->freq++; 
          
    }

    return sum; 
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize){
     *returnSize =0;
    
    if(root == NULL)
        return NULL; 
    
    
    int* ret ; 
    Hash* guser = NULL, *cur, *next; 
    int maxfreq = INT_MIN; 
    bool addval = false;   
    
    Sum(root,&guser);
    
    HASH_SORT(guser, cumfunc);
    ret = (int*)calloc(HASH_COUNT(guser), sizeof(int));
    
    HASH_ITER(hh, guser, cur, next){
        
        if(cur->freq != maxfreq && maxfreq ==INT_MIN){
          maxfreq = cur->freq; 
          addval = true; 
        }else{
            if( maxfreq == cur->freq )
                addval= true; 
            else
                addval = false; 
        }
        if(addval){
            ret[(*returnSize)++] = cur->sum; 
        }
        else
            break; 

    }
    
    HASH_DELETE(hh, guser, guser);
    return ret; 
}
