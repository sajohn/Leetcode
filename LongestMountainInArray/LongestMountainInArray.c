//The start of the detection of peak must start from base which need to be found first
// i.e. if(a[i=0] > a[i+1]) keep doing i++ until inflection for base comes. 
// at last base must be the right edge of the last peak 
/*
1. To find base we have to increment it by 1 unill we reach left valley
      /\        /
\    /  \      /
 \  /    \    /
  \/      \  /
           \/
2. Last valley to peak will not be counted as it has end+1 > arrSize so no update on len        
     /\        /
    /  \      /
   /    \    /
  /      \  /
          \/
3          
     /\        /\
    /  \      /  \
   /    \    /    \
  /      \  /      \  /
          \/        \/ 
           
*/

int max (int a, int b)
{
    return (a>b? a:b);
}
int longestMountain(int* arr, int arrSize){
    
    if(arr == NULL || arrSize <= 0)
        return 0; 
    
    int len =0, base =0, end = 0;  
   
    while(base < arrSize)
    {
        end = base; 
        if(end+1 < arrSize && arr[end]< arr[end+1]){
            
           while( end+1 < arrSize && arr[end]< arr[end+1] ){
               end++; 
           }
            
        if(end+1 < arrSize && arr[end]> arr[end+1]){
                
                  
           while( end+1 < arrSize && arr[end]> arr[end+1] ){
               end++; 
           }
             //Length is calculated here since laste end without peak to valley might not exist  
              len = max(len , end -base+1);     
         }      
      }
        //Find the base
        //else update the base
     
        base = max(end, base+1);
        
    }
    
    
    return len;
}
