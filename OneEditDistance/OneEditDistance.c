

bool isOneEditDistance(char * s, char * t){
    
    int lens = strlen(s);
    int lent = strlen(t);
    
   if((lens == 1 && lent == 0) || (lens == 0 && lent == 1))
       return true; 
    
    if(abs(lens-lent) >1 || strcmp(s, t) == 0)
        return false;
 int tcount[61] = {0}, scount[61] = {0},diff =0;
    
    
    if(lens==lent)
    {
        for(int i = 0; i < lent; i++)
            {
                if(s[i] !=t[i])
                    diff++;
                    
            if(diff >1)
                return false; 
            }
        return true; 
    }
    
    
    
    
    int ps =0, pt =0;
   
    if(lens>lent)
    {
        while(pt< lent){
            
            if(s[ps] == t[pt])
            {
                pt++; ps++;
            }
            else{
                if(pt < lent-1)
                   ps++;
                else if(pt == lent-1 && s[ps+1] == t[pt] && pt == ps)
                    return true; 
                
             for(int i = ps; i< lens; i++)
                  if(s[i] != t[pt++])
                      return false; 
             
                if(pt != lent)
                 return false; 
                
                return true; 
            }
        }
        if(ps+1 == lens)
            return true;
    }
    else{
         while(ps< lens){
            
            if(s[ps] == t[pt]){
                pt++; ps++;}
            else{
                 if(ps < lens-1)
                   pt++;
                else if(ps == lens-1 && s[ps] == t[pt+1] && pt == ps)
                    return true; 
                
             for(int i = ps; i< lens; i++)
                  if(s[i] != t[pt++])
                      return false; 
             
                if(pt != lent)
                 return false; 
                
                return true; 
            }
        }
        if(pt+1 == lent)
            return true;
    }
    
return false; 
}
