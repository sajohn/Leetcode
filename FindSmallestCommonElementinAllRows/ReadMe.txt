1198. Find Smallest Common Element in All Rows
Medium

148

11

Add to List

Share
Given a matrix mat where every row is sorted in strictly increasing order, return the smallest common element in all rows.

If there is no common element, return -1.

 

Example 1:

Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5
 

Constraints:

1 <= mat.length, mat[i].length <= 500
1 <= mat[i][j] <= 10^4
mat[i] is sorted in strictly increasing order.
Accepted
11,419
Submissions
15,232
Seen this question in a real interview before?

Yes

No
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Notice that each row has no duplicates.
Is counting the frequency of elements enough to find the answer?
Use a data structure to count the frequency of elements.
Find an element whose frequency equals the number of rows.
