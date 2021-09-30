

int repeatedStringMatch(char * a, char * b){

    if(a == NULL || b == NULL)
        return -1;
    int lena = strlen(a);
    int lenb = strlen(b);
    
    if(lena == 0 || lenb ==0)
        return -1; 
    
    if(strncmp(a, b, lenb) ==0)
        return 1; 
          
 /*
 If length of A is l and length of b is m
 if(l <=m)
 we need ceil(m/l) +1 space to find the the pattern existence. 
 Since pattern is should appear in group modulo it suffices to have length as ceil(m/l)+1
 
 */

    int countA[26]={0}, countB[26]={0};
    for(int i = 0; i < lena; i++)
        countA[a[i] -'a']++; 
    
    for(int i = 0; i < lenb; i++)
        countB[b[i] -'a']++; 
    

    for(int i = 0; i < 26; i++){
        if(countB[i] > 0 && countA[i] <=0)
                  return -1; 
    }
        
    int len = ceil(lenb/lena)+1; 
        
    char* tmp = (char*)calloc(((len+1)*lena)+1, sizeof(char)); 
    if(tmp == NULL)
        return -1; 

   int check = 0;
    for(int i = 0; i <len+1; i++)
    {    
        strcat(tmp, a);
        check++;
        if(strstr(tmp, b)!= NULL) 
            return check; 

    }
    
    return -1; 
}
