 int map[10][2] = {{0, 0}, {1, 1}, {2, INT_MIN}, {3, INT_MIN}, {4, INT_MIN}, {5, INT_MIN}, {6, 9}, {7, INT_MIN}, {8, 8},{9, 6}};
 int arr[5] = {0, 1, 6, 8, 9};
 int count = 0;

int isValid(int i)
{
     int num = 0, rm = 0, tmp = i; 
    
    
    while(i!=0)
    {
        
        rm  = i%10; 
        if(map[rm][1] == INT_MIN)
            return 0; 
        num = num*10 + map[rm][1];
        i = i/10; 
    }
    
    return (num!= tmp? 1:0);
}
   

 void dfs(long cur, int n)
    {
        if (cur > n)
            return;
        if (cur <= n && isValid(cur))
            count++;
        
        for (int i = 0; i < 5; i++)
        {
            if (i == 0 && cur == 0)
                continue;
            dfs(cur * 10 + arr[i], n);
        }
    }
    
int confusingNumberII(int n){
    
    count = 0; 
    dfs(0, n);
    
  return count; 
}
