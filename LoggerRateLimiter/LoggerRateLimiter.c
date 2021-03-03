
 typedef struct Logger{
    char* message;
    int timestamp;
    struct Logger** handle;
    UT_hash_handle hh;
} Logger;

/** Initialize your data structure here. */

 Logger* g_logger = NULL;

 Logger *findMessage( Logger** g_users, char* message) {

    Logger *s;

    HASH_FIND_STR(*g_users, message, s);
    return s;
}

void addMessage( Logger** g_users, char* message, int timestamp) {
    
    Logger *s;
    if(message)
     HASH_FIND_STR(*g_users, message, s);
    
    if (s == NULL) {
        s = ( Logger *)malloc(sizeof( *s));
    int len =0;

        len  = strlen(message);
        
        s->message = (char*)calloc(len+1, sizeof(char));
        if(s->message == NULL)
            return; 
        
        strcpy(s->message, message);
        s->timestamp = timestamp;
        
        HASH_ADD_KEYPTR(hh, *g_users, s->message, len, s);
        
    } else {
        if(timestamp - s->timestamp >10)
            s->timestamp = timestamp;
    }   
    
}

Logger* loggerCreate() {

Logger* logger = (Logger*)calloc(1, sizeof(Logger));
    
    if(logger)
    {
        logger->handle = &g_logger;
        return logger;
    }
    
    return NULL;
}

/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
bool loggerShouldPrintMessage( Logger* obj, int timestamp, char *message) 
{
  if( message == NULL || timestamp <0)
      return false;
    
     Logger* element = findMessage(obj->handle, message);
    
    if(element)
    { 
        int diff = timestamp - element->timestamp; 
        if(diff >=10)
        {
            element->timestamp = timestamp;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        addMessage(obj->handle, message, timestamp);
        return true;
    }
   
    return false;
}

void loggerFree(Logger* obj) {
     if(obj == NULL)
        return;

   Logger *s, *tmp;   
    
      HASH_ITER(hh, *obj->handle, s, tmp) {
          free(s->message);
      HASH_DEL(*obj->handle, s);
      free(s);
    }
    free(obj); 
}


/**
 * Your Logger struct will be instantiated and called as such:
 * Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 
 * loggerFree(obj);
*/
