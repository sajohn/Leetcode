

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    
    *returnSize = 0; 
    int* ret = (int*)calloc(2, sizeof(int));
    if(ret == NULL)
        return NULL; 
    
    int root = sqrt(area);
    double l= 0.0;
    int w = 0, diff =0, mindiff =INT_MAX,  truncated; 
    for(w = 1; w<= root; w++ ) {
         
        l = area/w; 
        
        truncated = (int)l;
        if (l != truncated || (area != l*w))
          continue; 
        
        diff = l-w; 
        if(diff >= 0)
        {
            if(diff < mindiff) {
                mindiff = diff; 
                ret[0] = (int)l; 
                ret[1] = (int)w; 
            }
        }
    }
 *returnSize = 2;    
return ret;  
}
