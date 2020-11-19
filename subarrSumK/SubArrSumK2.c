

//Like java solution we need to define find 

struct hashNode {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashNode *findUser(struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    return s;
}
int GetUserVal( struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    return s->val;
}
void AddUser(struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)malloc(sizeof(struct hashNode));
        s->key = key;
        s->val = 1;
        HASH_ADD_INT(*g_users, key, s);
    } else {
        s->val++;
    }    
}
int subarraySum(int* nums, int numsSize, int k){
  
    struct hashNode *g_users = NULL;
    
    int sum = 0, cnt = 0;
    g_users = NULL;
    //The first 0 is added to cover the case of target == sum == nums[i]
    AddUser(&g_users,0);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (findUser(&g_users, sum - k)) {
            cnt += GetUserVal(&g_users, sum-k);
        }
        AddUser(&g_users, sum);
    }
    
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
    HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
    
    return cnt;
}

