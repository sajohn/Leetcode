/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */
int FindValLeft(MountainArray* mountainArr, int low, int high, int target)
{
    //Search left then search right of peak
   int mid =0, midval=0;
    while(low <= high)
    {
        mid = low+ (high-low)/2;
        midval = get(mountainArr, mid);
        
        if(midval == target)
            return mid;
        else if(midval >target)
            high = mid -1;
        else if(midval < target)
            low = mid+1;
     }
    
    return -1;
}


int FindValRight(MountainArray* mountainArr, int low, int high, int target)
{
    //Search left then search right of peak
   int mid =0, midval=0;
    while(low <= high)
    {
        mid = low+ (high-low)/2;
        midval = get(mountainArr, mid);
        
        if(midval == target)
            return mid;
        else if(midval >target)
            low = mid +1;
        else if(midval < target)
            high = mid-1;
     }
    
    return -1;
}


int peakIndexInMountainArray(MountainArray* mountainArr, int target)
{
    int numsSize = length(mountainArr);

    if(mountainArr == NULL || numsSize == 0)
        return -1;
  
    if(numsSize==1)
            return 0;
    if(numsSize<3 )
        return (get(mountainArr, 0)>get(mountainArr, 1)? 0:1);
    
    int low =0, mid =-1, high = numsSize -1;
    int midval =0, midplusOneval =0, midminusOneval =0;
    while(low <=high)
    {
        mid = low+ (high-low)/2;
        if( mid == 0 || mid == numsSize-1)
            return mid;
       
        midval       = get(mountainArr, mid);
        midplusOneval = get(mountainArr, mid+1);
        midminusOneval  = get(mountainArr, mid-1);
        
        if(midval > midplusOneval && midval > midminusOneval)
            break;
        
        else
        {
           if(midval>midplusOneval)
              high = mid;
           
            else if( midval<midplusOneval)
              low = mid+1;
            
            else  if(midval<midminusOneval)
                high = mid-1;
           
            else  if( midval>midminusOneval)
                low = mid;   
        }
    }
    if(mid == -1)
        return -1;
    
    if(target == get(mountainArr, mid))
        return mid;
    
    int idx1=0, idx2 =0;
    
    idx1 = FindValLeft(mountainArr, 0, mid-1, target);
    if(idx1>=0)
        return idx1;
    idx2 = FindValRight(mountainArr, mid+1, numsSize -1, target);
     if(idx2>=0)
        return idx2;
       
return -1;
}


int findInMountainArray(int target, MountainArray* mountainArr) {
	
    if(mountainArr == NULL)
        return -1;
    
   return peakIndexInMountainArray(mountainArr, target);
}
