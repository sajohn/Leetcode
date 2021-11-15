

void duplicateZeros(int* arr, int arrSize)
{

if(arr == NULL || arrSize ==0)
    return;
    int count = 0, k =0, tmp =-1; 
   for(int i = 0; i < arrSize; i++)
       if(arr[i] == 0)
           count++; 
    if(count == 0)
        return ; 
    

    
    for(int i= 0; i <=arrSize-count && k < arrSize; i++)
    {
        if(arr[i] == 0){
            
            if(i+1< arrSize){
              tmp = arr[i+1];
            
            arr[k] = 0; k++; 
            arr[k] = 0; k++; 
            }
            else{
                 arr[k] = 0; k++; 
            }
        }
        else{
            arr[k++] = (tmp>0? tmp:arr[i]); 
        }
    }
   
 return; 
}
