//There could be a duplicate


bool validMountainArray(int* A, int ASize)
{ 
    
    if(A == NULL || ASize <3)
        return false;
    
    int start =0, end = ASize -1, mid =0;
    

     while(start+1 < end && A[start]<A[start+1])
         start++;
     
     if(start == end || start ==0)
         return false;
     
     
       while(start+1 <= end && A[start]>A[start+1])
         start++;
 
    
    return (start == end);

}
