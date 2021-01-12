

int sumOfDigits(int* A, int ASize){
    
    if(A == NULL || ASize ==0)
        return -1;
   int min = INT_MAX, sum =0, tmp =0; 
    for(int i = 0; i < ASize; i++)
    {
        if(A[i]<min)
        {
            min = A[i];
            tmp =0; sum = 0;
            while(A[i])
            {
                tmp = A[i]%10;
                A[i] /=10;
                sum +=tmp;
            }
        }
    }
    
     return (sum%2==0? 1:0);
}
