//If there is an a and previous b is seen delete that b reduce that b's count and increase deletion count 

int minimumDeletions(char * s){
    
    int count = 0, bcount =0, idx=0;
    
    if(s== NULL)
        return 0; 
    
    int len = strlen(s);
    
    
    for(int i =0; i < len; i++)
    {
        if(s[i] == 'b')
            bcount++; 
        
        if(bcount>0 && s[i] == 'a')
        {
            bcount--; 
            count++; 
        }
        
    }
    
    
    return count; 
}
