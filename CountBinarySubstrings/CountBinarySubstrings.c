

int countBinarySubstrings(char * s) {
    
    if(s == NULL )
        return 0; 
    
    int len = strlen(s);
    
   int prev_cnt =0, cur_cnt =1, res =0; 
    
    int i =0; 
       
    for( i = 1; i < len; i++)
    {
        if(s[i-1] == s[i]){
            cur_cnt++; 
        }
        else{
           res += (cur_cnt < prev_cnt? cur_cnt: prev_cnt);
            prev_cnt = cur_cnt; 
            cur_cnt = 1; 
        }
    }
    if(i == len)
    {
        res += (cur_cnt < prev_cnt? cur_cnt: prev_cnt);
    }
return res;
}



