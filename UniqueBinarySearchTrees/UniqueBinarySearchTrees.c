
// struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
// {
 
// if (nums == NULL || numsSize <= 0)
//     return NULL;

//   struct TreeNode* root = (struct TreeNode* )malloc(sizeof(struct TreeNode )); 
         
//     if(root == NULL)
//         return NULL;
//       int left =0, right = numsSize-1;
//       int mididx = left + (right -left)/2;
//       root->left = sortedArrayToBST(nums, mididx);
//       root->val = nums[mididx];
//       root->right = sortedArrayToBST(nums+mididx+1, numsSize -mididx-1);
  
// return root;
    
// } 

// int numTrees(int n){
    
//     if(n == 0)
//         return 0; 
//     int returnSize = 0, count = 0; 
    
//     int* tree = (int*)calloc(n, sizeof(int));
//     if(tree == NULL)
//         return 0; 
    
//      for(int i = 1; i<=n; i++)
//           tree[i-1] = i; 

//     int left = 0, right = 0, mid =0; 
    
//     struct TreeNode* root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
//     if(root == NULL)
//         return -1; 
    
//     for(int i = 1; i<=n; i++)
//     {
//       left = 0; right= i; 
//         mid = left + (right -left)/2;
      
//         root->val = tree[mid];
//         root->left = sortedArrayToBST(tree, mid);
//         root->right = sortedArrayToBST(tree+mid+1, n-mid-1);
        
//         if(root->left || root->right) 
//             count++;
        
//     }

//     return count; 
// }

// int table[20];

// int numTrees(int n){

//    if(n == 0 || n==2)
//        return n; 
    
//     table[n ] = 0; 

//     for(int i = 1; i<=n; i++)
//     {
//         table[n] += numTrees(i-1)*numTrees(n-i);
//     } 
    
//     return table[n];
// }    

// int numTrees(int n){
    
//     if(n == 0)
//         return 1; 
//   int count =0; 
//     for(int i = 1; i<= n; i++)
//     {
//        count += numTrees(i-1)* numTrees(n-i);
//     }
    
//     return count; 
// }


int table[1024];

int countBST(int start, int end) {
    
    int sum = 0;
    
    if (start >= end) {
        return 1;
    }

    for (int i = start; i <= end; i++) {
        
        int left = countBST(start, i - 1);
        int right = countBST(i + 1, end);
        
        sum += left * right;
     
    }
    
    return sum;
}

int numTrees(int n) {

    
    if (n == 0) return 1;
    return countBST(1, n);
}

