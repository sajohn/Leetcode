int kthGrammar(int n, int k) { 
        int mid; 
        if(n == 1 && k == 1)
            return 0; 
        else{ 
            mid = pow(2,n-1)/2; 
            
            if(k <= mid){
                return kthGrammar(n-1,k); 
            }
            else{
                return !kthGrammar(n-1, k-mid);  /// just the oposit of bit in first half if k > mid
            }
        }
        return -1;
    }
