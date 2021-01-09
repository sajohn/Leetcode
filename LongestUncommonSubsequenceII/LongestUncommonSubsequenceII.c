
//What solution is saying is if strings don't match at any point they are not subsequence
//If one of the string exausts its length in comparision the strings are not subsequence 
int max(int a,int b)
{
    return a>b?a:b;
}
bool isSubsequence(char* a, char* b)
{
    if(a== NULL || b==NULL)
        return false;
    
    int lena = strlen(a);
    int lenb = strlen(b);
    if(lena < lenb)
        return false;
    int j =0;
    for(int i =0; i < lena; i++)
    {
        if(a[i]==b[j] && j<lenb)
            j++;
    }
    
    if(j == lenb)
        return true;
    
 //not a subsequence   
return false;

}


int findLUSlength(char ** strs, int strsSize){
if(strs == NULL || strsSize ==0)
    return 0;
    
    int ret =-1, j =0, i=0; 
    for( i =0; i < strsSize; i++)
    {
        for( j =0; j< strsSize; j++)
        {
            if(j ==i)
                continue;
            
            if(isSubsequence(strs[j], strs[i]))
                break;
            
        }
        if(j == strsSize)
            ret = max(ret, strlen(strs[i]));
        
    }
    return ret;
}
