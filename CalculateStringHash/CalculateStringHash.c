long GetHash(char* str)
{
   
    if(str == NULL)
        return INT_MIN;
    unsigned long hash = 5381;
    int c;
     while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
}

