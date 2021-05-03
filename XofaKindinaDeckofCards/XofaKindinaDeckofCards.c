//If GCD of all the numbers is greater than 1 we have a solution based on count
// Simnply because cards can be gropued based on GCD as minimum

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
}Deck;


bool hasGroupsSizeX(int* deck, int deckSize){

    if(deck == NULL || deckSize == 0)
        return false; 
    
    Deck* guser= NULL, *element = NULL, *tmp = NULL; 
    
    
      for (int i = 0; i < deckSize; i++) {
         int x = deck[i];
          HASH_FIND_INT(guser, &x, element);
          if(element == NULL)
          {
              element = (Deck*)calloc(1, sizeof(Deck));
              if(element == NULL)
                  return false; 
              element->key = deck[i];
              element->value = 1; 
              
              HASH_ADD_INT(guser, key, element);
          } else {
              element->value += 1; 
          }
      }
  
    int result = 0; 
    
    HASH_ITER(hh, guser, element, tmp) {
    
    result =  gcd(element->value, result);
    HASH_DEL(guser, element);  /* delete; users advances to next */
    free(element);             /* optional- if you want to free  */
  }

   if(result<=1)
     return false; 
    
    return true; 
}
