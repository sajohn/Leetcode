
int fib(int N)
{
    if(N == 0 || N==1)
        return N;
    int  curf=0, prevf =0, res=0;
    
    curf = 1;
    
    for(int i =1; i<N; i++)
    {
      res = curf+prevf;
        prevf = curf;
        curf = res;
    }
    
    return res;
}
