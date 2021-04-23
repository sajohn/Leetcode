////Calculate left limit of each rectangle smaller than itself
////Calculate right limit of each rectangle smaller than itself  
////Area of each rectangle = (right -left)* width
////Find the maximum of all areas 
////From then each row needs to have addendum from previous row and calculate area or rectangle which is maximum 
    
int max(int a , int b)
{
    return (a>b?a:b);
}

int largestRectangleArea(int* heights, int heightsSize)
{
    if(heights == NULL || heightsSize ==0)
        return -1;
    
    
    int maxarea =INT_MIN, top =-1,  leftlimit[heightsSize], rightlimit[heightsSize];
    
    int stack[heightsSize];
 
    for(int i = 0; i < heightsSize; i++)
    {
        if(top == -1){
         leftlimit[i] = i;
         stack[++top] = i;
        }
        else
        {
                //POP untill value < heights[i]  or stack is empty
                while(top != -1 )
                {
                    if(heights[i]<=heights[stack[top]])
                    {
                      stack[top--] = -1;
                       // top--;
                    }
                    else
                        break;
                }
                if(top == -1){
                   leftlimit[i] = 0;
                   stack[++top] = i;
                }
                else
                {
                    leftlimit[i] = stack[top]+1;
                    stack[++top] = i;
                    
                }
        }
 
    }
 
    top = -1;
    
    for(int i = heightsSize-1;i >= 0; i--)
    {
        if(top == -1){
         rightlimit[i] = i;
         stack[++top] = i;
        }
        else
        {

                //POP untill value < heights[i]  or stack is empty
                while(top != -1 )
                {
                  if( heights[i]<=heights[stack[top]])
                  {
                    stack[top--] = -1;
                    //top--;
                  }
                    else 
                        break;
                }
                if(top == -1){
                   rightlimit[i] = heightsSize -1;
                   stack[++top] = i;
                }
                else
                {
                    rightlimit[i] = stack[top]-1;
                    stack[++top] = i;
                    
                }
        }
    }
    
    for(int i = 0; i < heightsSize; i++)
        maxarea = max(maxarea, (rightlimit[i] - leftlimit[i] +1)*heights[i] );
    
    return maxarea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    
    if(matrix == NULL ||  matrixSize ==0 || matrixColSize == NULL)
        return 0;
    
    int maxarea = INT_MIN, area=0; 
    
    int* tmp = (int*)calloc( *matrixColSize, sizeof(int));
    if(tmp == NULL)
        return 0;
    
    for(int i=0; i < matrixSize; i++){
        if(i ==0){
            for(int j = 0; j < *matrixColSize; j++)
             { tmp[j] = matrix[0][j] -'0';}
            area = largestRectangleArea(tmp, *matrixColSize);

        }
        else
        {
            for(int j = 0; j < *matrixColSize; j++)
            {
                if(matrix[i][j] -'0' == 0)
                    tmp[j] = 0;
                else
                    tmp[j] +=(matrix[i][j] -'0');
            }
              area = largestRectangleArea(tmp, *matrixColSize);
        }
        if(area>maxarea)
            maxarea = area;
    }

    return maxarea;
}
