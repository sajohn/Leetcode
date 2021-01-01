struct Unique
{
    int val;
    int count;
    UT_hash_handle hh;
};
int cmp(struct Unique* a, struct Unique* b)
{
     return (b->val - a->val);    
}

int largestUniqueNumber(int* A, int ASize)
{
    int max = INT_MIN;
    
    struct Unique *g_users = NULL, *element;
    for(int i =0; i < ASize; i++)
    {
      HASH_FIND_INT(g_users, &A[i], element);
        if(element == NULL)
        {
            element = (struct Unique*)calloc(1, sizeof(* element));
            if(element == NULL)
                return NULL;
            
            element->val = A[i];
            element->count = 1;
            max = (max<A[i]? A[i]: max);
            HASH_ADD_INT(g_users, val, element);
        }
        else
        {
           element->count++;
           if(max == A[i])
               max = -1;
        }
    }
    
        HASH_SORT(g_users, cmp);
        for(element=g_users; element != NULL; element=(struct Unique*)(element->hh.next)) { 
            if(element->count==1){
                max =  element->val;
                break;
            }
        }
                
    return max;
}
