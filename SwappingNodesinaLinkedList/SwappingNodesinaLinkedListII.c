// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */


// struct ListNode* swapNodes(struct ListNode* head, int k){
    
//     if(head == NULL)
//         return NULL;

    
//     struct ListNode* tmpnode, *front, *tail;
//     int count = 0,count2 =0, tmp =0, idx =0; 
//     int* ret = NULL;
//     tmpnode = head;
    
//     while(tmpnode != NULL){
//         count++; 
//         if(count == k)
//             front = tmpnode;
//         tmpnode = tmpnode->next;
//     }

//       tmpnode = head;
//       while(tmpnode != NULL){
//         count2++; 
//         if(count2 == count -k+1)
//         {
//             tail = tmpnode;
//             break;
//         }
//         tmpnode = tmpnode->next;
//     }
//     if(count < k || count -k <0) return NULL;
    
//     tmp = front->val;
//     front->val = tail->val;
//     tail->val = tmp;
        
// return head;
    
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    
    if(head == NULL)
        return NULL;

    
    struct ListNode* tmpnode, *front, *tail;
    int count = 0, tmp =0, idx =0; 
    int* ret = NULL;
    tmpnode = head;
    
    while(tmpnode != NULL){
        count++; 
        if(count == k){
            front = tmpnode;
            tail = head;
        }
         if(count!= k && tail != NULL)
            tail = tail->next;
        
        tmpnode = tmpnode->next;
    }


    if(count < k || count -k <0) return NULL;
    
    tmp = front->val;
    front->val = tail->val;
    tail->val = tmp;
        
return head;
    
}
