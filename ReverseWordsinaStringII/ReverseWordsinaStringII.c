void reverseWords(char *str, int strSize)
{
    if (str == NULL || strSize <= 1)
        return;

    int i = 0, j = 0; 
    while (i < strSize)
    {
        while (i < j || (i < strSize && str[i] == ' '))
            i++; 
    
        while (j < i || (j < strSize && str[j] != ' '))
            j++; 
        
        reverseWord(str, i, j - 1);
    }
printf("%s", str);
    reverseWord(str, 0, strSize - 1);
}

void reverseWord(char *str, int start, int end)
{
    while (start < end)
    {
        char tmp = str[start]; 
        str[start] = str[end];
        str[end] = tmp;
       
        start++;
        end--;
    }
}
