

int longestOnes(int* A, int ASize, int K){

   if(A == NULL|| ASize ==0 )
       return 0;
    
    int max_length = 0, max_count =0, curr_count =0,win_start=0, win_end =0;
    int countarr[2] = {0};
    
    for( win_end =0; win_end < ASize; win_end++ )
    {
         curr_count = ++countarr[A[win_end]];
         /*Because I'm including this 1 and want to know if window can still perform operation 
           when max count is < current and it is for including 1 only. 
         */
         if(curr_count>max_count && (A[win_end]==1))
            max_count = curr_count;
        //This max count reflect w.r.t 1 so I can remove the other start value from window for below condition. 
        while(win_end+1-win_start-max_count>K )
        {
           countarr[A[win_start]]--;
            win_start++;
        }
        if(max_length <(win_end+1-win_start) )
            max_length = (win_end+1-win_start);
    }    
    
     if(K ==0 && countarr[1]==0)
         return 0;
    
    return max_length;
}
