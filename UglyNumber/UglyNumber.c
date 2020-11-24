
bool isUgly(int num)
{
   if(num <1)
       return false;
    
  while(num)
  {
      if(num%2 == 0)
          num = num/2;
      else if(num%3 == 0)
          num = num/3;
      else if(num%5 ==0)
          num = num/5;
      else if(num==1)
          break;
      else
          return false;
  }
    
    return true;
}



