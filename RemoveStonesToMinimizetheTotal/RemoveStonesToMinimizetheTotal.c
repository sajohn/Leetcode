
void heapify_bottom_top(int* arr,int index){
    int parent=(index-1)/2;
    
    if(parent>=0 && arr[index] > arr[parent]){
        int temp=arr[index];
        arr[index]=arr[parent];
        arr[parent]=temp;
        heapify_bottom_top(arr,parent);
    }
}

void heapify_top_bottom(int* arr,int parent,int size){
    int left=(2*parent)+1;
    int right=(2*parent)+2;
    
    int max=parent;
    
    if(left<size  && left >=0 && arr[left]>arr[max]){
        max=left;
    }
    if(right<size && right >= 0 && arr[right]>arr[max]){
        max=right;
    }
    
    if(max!=parent){
        int temp=arr[max];
        arr[max]=arr[parent];
        arr[parent]=temp;
        heapify_top_bottom(arr,max,size);
    }
    
    
}

void kthLargestCreate( int* nums, int numsSize) {
   
     for(int i=numsSize/2 -1;i>=0; i--) 
         heapify_top_bottom(nums, i, numsSize);
     
}



int minStoneSum(int* piles, int pilesSize, int k){
    
    if(piles == NULL || pilesSize == 0)
        return 0; 
    
    int sum = 0; 

   kthLargestCreate(piles, pilesSize);
    
    for(int i =0;i <k; i++){
        
        piles[0] = (int)ceil((float)piles[0] /2);
     
        heapify_top_bottom(piles, 0, pilesSize);
        
    }
       for(int i =0;i <pilesSize; i++){
           sum+=piles[i];
       }
    
    return sum; 
}
