logo
Explore
Problems
Interview
Contest
Discuss
Store
🚀 August LeetCoding Challenge 2021 🚀
0
Description
Solution
Discuss (204)
Submissions
1886. Determine Whether Matrix Can Be Obtained By Rotation
Easy

211

26

Add to List

Share
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 

Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.
Accepted
14,492
Submissions
26,817
Seen this question in a real interview before?

Yes

No

Problems

Pick One

Prev
/226

Next

Autocomplete





▤
void Transpose(int** matrix, int matrixSize, int* matrixColSize)
{
    int tmp =0; 
    for(int i =0; i <  matrixSize ; i++)
    {
         for(int j =i; j < *matrixColSize; j++)
         {
             tmp =  matrix[j][i];
          
             matrix[j][i] =  matrix[i][j];
             matrix[i][j] = tmp;  
         }
    }
    

}
    
void Reflect(int** matrix, int matrixSize, int* matrixColSize)
{
    int tmp =0; 
     for(int i =0; i < matrixSize; i++)
    {
         for(int j =0; j < (*matrixColSize)/2; j++)
         {
            tmp = matrix[i][j];
             matrix[i][j] =  matrix[i][*matrixColSize-j-1];
             matrix[i][*matrixColSize-j-1] = tmp;
         }
    }
    
}


void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
        return ;
    
    Transpose(matrix, matrixSize,matrixColSize);
    Reflect(matrix, matrixSize,matrixColSize);
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){

      if(mat == NULL || matSize == 0 || matColSize == NULL || target == NULL || targetSize == 0 || targetColSize == 0)
        return false;
     
    int count = 0; 
    
     for(int ii =0; ii< 4; ii++) {
        for(int k = 0; k< matSize; k++) {
            
           if(memcmp(mat[k], target[k], (matSize)*sizeof(int)) == 0)
               count++;
            else
                break; 
            
            if(count == matSize)
                return true;
          } 
          rotate(mat, matSize, matColSize);
     }
        
    return false; 
}
1
void Transpose(int** matrix, int matrixSize, int* matrixColSize)
2
{
3
    int tmp =0; 
4
    for(int i =0; i <  matrixSize ; i++)
5
    {
6
         for(int j =i; j < *matrixColSize; j++)
7
         {
8
             tmp =  matrix[j][i];
9
          
10
             matrix[j][i] =  matrix[i][j];
11
             matrix[i][j] = tmp;  
12
         }
13
    }
14
    
15
​
16
}
17
    
18
void Reflect(int** matrix, int matrixSize, int* matrixColSize)
19
{
20
    int tmp =0; 
21
     for(int i =0; i < matrixSize; i++)
22
    {
23
         for(int j =0; j < (*matrixColSize)/2; j++)
24
         {
25
            tmp = matrix[i][j];
26
             matrix[i][j] =  matrix[i][*matrixColSize-j-1];
27
             matrix[i][*matrixColSize-j-1] = tmp;
28
         }
29
    }
30
    
31
}
32
​
33
​
34
void rotate(int** matrix, int matrixSize, int* matrixColSize){
35
    
36
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
37
        return ;
38
    
39
    Transpose(matrix, matrixSize,matrixColSize);
40
    Reflect(matrix, matrixSize,matrixColSize);
41
}
42
​
43
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){
44
​
45
      if(mat == NULL || matSize == 0 || matColSize == NULL || target == NULL || targetSize == 0 || targetColSize == 0)
46
        return false;
47
     
48
    int count = 0; 
49
    
50
     for(int ii =0; ii< 4; ii++) {
51
        for(int k = 0; k< matSize; k++) {
52
            
53
           if(memcmp(mat[k], target[k], (matSize)*sizeof(int)) == 0)
54
               count++;
55
            else
56
                break; 
57
            
58
            if(count == matSize)
59
                return true;
60
          } 
61
          rotate(mat, matSize, matColSize);
62
     }
63
        
64
    return false; 
65
}
Your previous code was restored from your local storage.
Reset to default
Testcase
Run Code Result
Debugger
  
Console 
Use Example Testcases

Run Code

Submit
Type here...(Markdown is enabled)
​
Saved
search problems



Depth-First Search
This list is empty.
