typedef struct 
{
  int val;
  UT_hash_handle hh;
    
}hashset;

int newNumber(int num)
{
    int sum = 0, tmp =0; 
    while(num)
    {
        tmp = num%10;
        num /=10;
        sum +=tmp*tmp;
    }
    
    return sum;
}

void AddVal(hashset** guser, int val)
{
     hashset* element;
    
    element = (hashset*)calloc(1, sizeof(*element));
    if(element == NULL)
        return; 
    
    element->val = val;
    
    HASH_ADD_INT(*guser, val, element);
}

hashset* findVal(hashset** guser, int val)
{
    hashset* element;
    
    HASH_FIND_INT(*guser, &val, element);
        return element;
}

bool isHappy(int n)
{
 hashset* guser = NULL, *element; 
    
    if(n == 0 || n == 4 || n ==2)
        return false;

    
    while(n != 1 && !findVal(&guser,n))
    {
        AddVal(&guser, n);
        n = newNumber(n);
    }
    
   return (n ==1);
}
