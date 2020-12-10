/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */

int _read(char* buf, int n) 
{
   
    if(n ==0)
    {
        *buf = '\0';
        return 0; 
    }
    
    int readcount = n/4;
    int remains = n%4;
    int count =0, totalcount =0; 
    char* tmpbuff = (char*)calloc(4, sizeof(char));
    if(tmpbuff==NULL)
        return 0; 
    
    if(remains>0)
        readcount++;
   
    
    while(readcount >0)
    {
        count =read4(tmpbuff);
        totalcount +=count;

        if(totalcount>n)
        {
            totalcount = totalcount -count+remains;
            count = remains;
        }
            
        if(tmpbuff!= NULL && count !=0)
        {
      
          memcpy(buf, tmpbuff, count);
            buf = buf+count;
        }
        else if(tmpbuff== NULL || count == 0)
        {
            count =0; 
            break;
        }
        count = 0; 
        readcount--;
        memset(tmpbuff, 0, 4);
    }
  
    return totalcount;
    
}
