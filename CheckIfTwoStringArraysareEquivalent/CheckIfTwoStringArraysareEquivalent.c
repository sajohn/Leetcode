

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size)
{
    if(word1 == NULL || word2 == NULL )
        return false;
     if((word1 == NULL && word2 == NULL) || (word1Size == 0 && word2Size == 0))
        return true;
        
    int i =1, j=1; 
    char* str1, *str2;
    str1 = (char*) calloc(strlen(word1[0])+1, sizeof(char));
    str2 = (char*)calloc(strlen(word2[0])+1, sizeof(char));
    strcpy(str1, word1[0]);
    strcpy(str2, word2[0]);
    
       while(i < word1Size || j< word2Size)
       {
           if(i<word1Size)
           {
               if(word1[i])
               {
                 str1 = (char*)realloc(str1, strlen(str1)+ 1 +strlen(word1[i]));
                 strcat(str1, word1[i++]);
               }
           }
            if(j<word2Size)
            {
                 if(word2[j])
               {
                 str2 = (char*)realloc(str2, strlen(str2)+ 1+ strlen(word2[j]));
                 strcat(str2, word2[j++]);
               }
            }
       }
    
       if(strcmp(str1, str2) ==0)
           return true;
    
       return false;
}
