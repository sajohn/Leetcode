bool canReach (char * s, int minJump, int maxJump) {
    int i, j;
    if(s == NULL)
        return false; 
    int len = strlen(s);
    
    
    s[0] = '2';//identifier to reduce overhead of revisiting 
    for (i = 1, j = 0; s[i]; i++) {
        if (s[i] == '0') {
            while (j < i && (s[j] != '2' || j + maxJump < i)) {
                j++;
            }
            if (s[j] == '2' && j + minJump <= i) {
                s[i] = '2';
            }
            if(i == len-1 && s[i] == '2')
                return true; 
        }
    }
    
    return s[i-1] == '2';
}
