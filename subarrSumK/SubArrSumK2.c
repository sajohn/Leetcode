

struct hashNode {
    int key;
    int val;
    UT_hash_handle hh;
};
struct hashNode *g_users = NULL;
struct hashNode *findUser(int key) {
    struct hashNode *s;
    HASH_FIND_INT(g_users, &key, s);
    return s;
}
int getUserVal(int key) {
    struct hashNode *s;
    HASH_FIND_INT(g_users, &key, s);
    return s->val;
}
void addUser(int key) {
    struct hashNode *s;
    HASH_FIND_INT(g_users, &key, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)malloc(sizeof(struct hashNode));
        s->key = key;
        s->val = 1;
        HASH_ADD_INT(g_users, key, s);
    } else {
        s->val++;
    }    
}
int subarraySum(int* nums, int numsSize, int k){
    int sum = 0, cnt = 0;
    g_users = NULL;
    addUser(0);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (findUser(sum - k)) {
            cnt += getUserVal(sum-k);
        }
        addUser(sum);
    }
    return cnt;
}


