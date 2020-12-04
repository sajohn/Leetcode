
struct hashNode {
    int key;
    int count;
    UT_hash_handle hh;
};

struct hashNode *FindUser(struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    return s;
}
int GetCount(struct hashNode** g_users, int key)
{
    struct hashNode* s;
     HASH_FIND_INT(*g_users, &key,s);
    if (s == NULL) 
        return -1;
    else 
        return s->count;
}

void AddUser(struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)malloc(sizeof(struct hashNode));
        s->key = key;
        s->count =1 ;
        HASH_ADD_INT(*g_users, key, s);
    } 
    else
    {
        s->count++;
    }
}

//Here left boundary is discarded is not needed in further check (sliding is sufficient condition to get the next mininum)


char * minWindow(char * s, char * t)
{
    struct hashNode *g_users = NULL, *element;

    if(s == NULL)
      return NULL;
    if(t == NULL && s!=NULL)
        return NULL;
    
    int lens = strlen(s);
    int lent = strlen(t);  
  
    
    //Total 256 ASCII chars can be there
    
    int left =0, right =0, min = INT_MAX, count[256]={0},uniqueCount =0, minval=0, idx[3] = {0};
    
    for(int i =0; i < lent; i++)
         AddUser(&g_users, t[i]);
    
    uniqueCount = HASH_COUNT(g_users);
    if(uniqueCount >lens)
        return "";
    
 for(int i=0; i < lens; i++)
 {
      count[s[i]]++;
    
     if(count[s[i]] == GetCount(&g_users, s[i]))
     {
         minval++;
        
         if(left<=i && minval == uniqueCount )
         {  
                 min = abs(i +1- left) < min? abs(i+1 - left):min;
                 //Save i left min strncpy(ret, &s[left], min+1);
             if(abs(i +1- left) <= min)
             {
                  idx[0] = left;
                  idx[1] = i;
                  idx[2] = min;
             }
                 if(count[s[left]]>0)
                    count[s[left]]--;
               if(count[s[left]] < GetCount(&g_users, s[left]))
                   minval--;
                 left++;   
         }
      
         while(left<=i && minval == uniqueCount )
         {
             
             if(count[s[left]] < 0 && left < i)
             {
                 min = abs(i +1- left) < min? abs(i+1 - left):min;
                 //strncpy(ret, &s[left], min+1);
                  if(abs(i +1- left) <= min)
             {
                  idx[0] = left;
                  idx[1] = i;
                  idx[2] = min;
             }
                 count[s[left]]--;
                 left++;
             }
             else if(count[s[left]] >=  GetCount(&g_users, s[left]) && left <= i){
             
                 min = abs(i +1- left) < min? abs(i+1 - left):min;
                  //strncpy(ret, &s[left], min+1);
                  if(abs(i +1- left) <= min)
             {
                  idx[0] = left;
                  idx[1] = i;
                  idx[2] = min;
             }
                 if(count[s[left]]>0)
                    count[s[left]]--;
              if(count[s[left]] < GetCount(&g_users, s[left]))
                   minval--;
                 left++;   
         }
         
      } 
   }
 }
    struct hashNode *current_user, *tmp;
    HASH_ITER(hh, g_users, current_user, tmp) {
    HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
    if(min==INT_MAX || min == 0)
        return "";
    
 char* ret = (char*)calloc(lens+1, sizeof(char));
    if(ret == NULL)
        return NULL;
    strncpy(ret, &s[idx[0]], min+1);
    ret[min] = '\0';
   return ret;
}
    



