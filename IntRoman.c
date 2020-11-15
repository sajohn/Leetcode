typedef struct{
   char *str;
   int val;
}numeral;

int maxNume(numeral *nu, int num){
   int i, index;
   for(i = 0; i<15; i++){
      if(nu[i].val <= num)
         index = i;
   }
   return index;
}
char* convertIntToRoman(numeral *nu, int num, char* ans){
int number;
 
 numeral nume[15] = {{"I",1},{"IV",4},{"V",5},{"IX",9}, {"X",10},{"XL",40},{"L",50},{"XC",90},
{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000},{"MMMM",4000},{"V'",5000}};
  
   int max;
   if(num != 0){
      max = maxNume(nu, num);
     
     //  printf("%s", nu[max].str);
       strcat(ans, nu[max].str);
      num -= nu[max].val;
      convertIntToRoman(nu, num, ans);
       
       return ans;
   }
 return "";
}
char * intToRoman(int num)
{
 numeral nume[15] = {{"I",1},{"IV",4},{"V",5},{"IX",9}, {"X",10},{"XL",40},{"L",50},{"XC",90},
                     {"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000},{"MMMM",4000},{"V'",5000}};
  
static char ans[20] = {0};
memset(ans, 0, (20));
    
    return convertIntToRoman(nume, num , &ans);
}

