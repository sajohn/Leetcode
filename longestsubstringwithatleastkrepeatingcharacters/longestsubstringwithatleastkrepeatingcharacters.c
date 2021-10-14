/*
If the string has < k element it cannot be the part of the solution so we descard. 
By descard we mean we need to split the string and look in two split search space recursively
The length returned (i.e. the string is searched untill condition meet on that string containing the k characters) 
is compared with other half the sting. 
*/

int max(int a ,int b){
    return (a>b? a:b);
}
char* substr(const char *src, int m, int n)
{
    int len = n - m+1;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
     for (int i = m; i <= n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
 
    *dest = '\0';
    return dest - len;
}
int longestSubstring(char * s, int k){
    
    if(k <=1)
        return strlen(s);
   int len = strlen(s);
    
    if(len <k)return 0; 
    
    int freqMap[26] = {0};

    for(int i = 0; i < len; i++)
       freqMap[s[i] -'a']++; 
    //Now the issue is we need to find the first index which is < k 
    int idx =0; 
    while(idx < len && freqMap[s[idx]-'a'] >=k) idx++; 
    
    if(idx >= len)return len; 
    
    int len1 = longestSubstring(substr(s, 0, idx-1), k);
    
    while(idx < len && freqMap[s[idx]-'a'] < k) idx++; 
    
    int len2 = idx < len? longestSubstring(substr(s, idx, len-1), k) : 0;
        
    return max(len1, len2);
    
    
}
