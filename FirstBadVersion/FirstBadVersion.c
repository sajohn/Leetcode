// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    if( n == 0)
        return 0; 
    
    int start = 1, end = n, mid = 0, res =0; 
    
    while(start <= end)
    {
        mid = start + (end - start)/2; 
        
        if(isBadVersion(mid)){
            res = mid; 
            end = mid-1; 
        } else {
            start = mid+1; 
        }
    }
    
    return res; 
    
}
