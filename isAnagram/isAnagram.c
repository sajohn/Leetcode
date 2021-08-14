

bool isAnagram(char * s, char * t)
{
  int count26[26];
    
  memset(count26, 0, 26*sizeof(int));
    
    if(s == NULL || t == NULL)
        return false;
  
    int slen = strlen(s);
    int tlen = strlen(t);
 
    for(int i = 0; i < slen; i++)
        count26[s[i]-'a']++;
  
    for(int i=0; i < tlen; i++)
        count26[t[i]-'a'] = count26[t[i]-'a'] -1;
           
    for(int i = 0; i < 26; i++)
    {
        if(count26[i]!=0)
        {
            return false;
        }
    }
   
    return true;
}
