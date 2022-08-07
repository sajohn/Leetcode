

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
//     if(A == NULL || ASize ==0 ){
//         *returnSize = 0; 
//         return NULL; 
//     }

//     int left= 0, right = ASize -1, tmp = 0; 
  

//     while(left < right )
//     {
//         while(right >=0 && A[right]&1 ){
//             right--; }
        
//         while(left < ASize && (A[left] % 2 == 0 || A[left] == 0)) {
//             left++; 
//         }
        
//         if(left < right && left < ASize && right >0)
//         {
//             tmp = A[left];
//             A[left] = A[right];
//             A[right] = tmp;
//         }
//         left++; right--; 
//     }
    
//     *returnSize = ASize;
    
//     return A;
// }

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    if(A == NULL || ASize ==0 ){
        *returnSize = 0; 
        return NULL; 
    }
    int idx = -1, tmp =0; 
    
    for(int i =0; i < ASize; i++){
        
        if(A[i]%2 == 0  ){
            
            idx+=1; 
            tmp = A[idx];
            A[idx] = A[i];
            A[i] = tmp;
        }

    }
    
    *returnSize = ASize; 
    return A;
}
