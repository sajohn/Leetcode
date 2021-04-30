/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

typedef struct {
  char * buf;
  int idx;
  int count; 
}
Solution;

/** initialize your data structure here. */
Solution * solutionCreate() {

  Solution* s = (Solution *) calloc(1, sizeof(Solution));
  if (s == NULL)
    return NULL;
  s->idx = 0;
  s->count = 0;
  return s;
}

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(Solution* obj, char* buf, int n) {

  if (n == 0) {
    * buf = '\0';
    return 0;
  }

  int readcount = n/4;
  int remains = n%4;
    
  int count = 0, totalcount = 0;

   char* tmpbuff = calloc(4, sizeof(char)); 
    if(tmpbuff == NULL)
        return INT_MIN; 
    
 if (remains > 0)
    readcount++; //readcount +1 times read call nedds to be done for the buffer fill 

    //idx is a read index last time. 
    //Total count is a count of buffer in buff
    
  while (readcount > 0) {
      
    count = read4(tmpbuff);
    totalcount = obj->count + count;
      
      if(count != 0){
           // memcpy new data to local buffer and increase index
          obj->buf = realloc(obj->buf, totalcount+1);
          memcpy(obj->buf+obj->count, tmpbuff, count);
          
          //memcpy(buf+obj->count, obj->buf+obj->count, count);
          obj->count = totalcount;
          obj->buf[totalcount] = '\0';
      }
      
    count =0; 
    memset(tmpbuff, 0, 4); 
    readcount--;
  }

    //After reading for i th request now return requested count. 
    
   if(obj->count - (obj->idx)>0)
   {
       if(obj->count -(obj->idx) >= n)
       {
           memcpy(buf, obj->buf+obj->idx, n);
           obj->idx+=n;
           return n;
       } else {
           int copycount = obj->count -obj->idx;
           memcpy(buf, obj->buf+obj->idx, copycount);
     
        
           obj->idx+=copycount; 
           return copycount;
       }

   } else {
        return 0;
    }

 return -1; 

}
