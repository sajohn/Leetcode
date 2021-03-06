//Like java solution we need to define find 

struct hashNode {
    int key;
    int val;
    int idx;
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
void AddUser(struct hashNode **g_users, int key, int idx) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)malloc(sizeof(struct hashNode));
        s->key = key;
        s->val = 1;
        s->idx = idx;
        HASH_ADD_INT(*g_users, key, s);
    } else {
        s->val++;
    }    
}
int maxSubArrayLen(int* nums, int numsSize, int k){
  
    struct hashNode *g_users = NULL, *element;
    
    int sum = 0, cnt = 0, max = 0;
    g_users = NULL;
    
    if(nums == NULL || numsSize == 0)
        return 0;
    //The first 0 is added to cover the case of target == sum == nums[i]
    AddUser(&g_users,0, -1);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (element = findUser(&g_users, sum - k)) {
            max = abs(i - element->idx) > max? abs(i - element->idx):max;
            cnt += GetUserVal(&g_users, sum-k);
        }
        AddUser(&g_users, sum, i);
    }
    
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
    HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
    
    return max;
}




