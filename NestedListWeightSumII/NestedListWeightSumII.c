/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */


// int depthSumInverse(struct NestedInteger** nestedList, int nestedListSize){

// }


void getmaxVal(struct NestedInteger** nestedList, int nestedListSize, int depth, int *maxDepth){
    
    if(nestedList == NULL || nestedListSize == 0)
        return ; 
            
    for(int i =0; i < nestedListSize ; i++){
 
        if(NestedIntegerIsInteger(nestedList[i])){
            *maxDepth = *maxDepth > depth? *maxDepth: depth; 
        } else{
            getmaxVal(NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]), depth+1, maxDepth);
        }
    }
}


void depthValue(struct NestedInteger** nestedList, int nestedListSize, int* total, int depth, int *maxDepth){
    
    if(nestedList == NULL || nestedListSize == 0)
        return ; 
            
    for(int i =0; i < nestedListSize ; i++){
 
        if(NestedIntegerIsInteger(nestedList[i])){
            
            int weight =  *maxDepth - depth+1;

            *total += ((weight)*NestedIntegerGetInteger(nestedList[i]));
        }
        else{
            depthValue(NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]), total, depth+1, maxDepth);
        }
    }
    
    return; 
}

int depthSumInverse(struct NestedInteger** nestedList, int nestedListSize){
    
    if(nestedList == NULL || nestedListSize == 0)
        return 0; 
    
    int total = 0, maxDepth = 1; 
    
    getmaxVal(nestedList,nestedListSize, 1, &maxDepth);
    depthValue(nestedList,nestedListSize, &total, 1, &maxDepth);
    
     return total; 
}
