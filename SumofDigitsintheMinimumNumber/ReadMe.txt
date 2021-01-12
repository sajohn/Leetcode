1085. Sum of Digits in the Minimum Number
Easy

50

113

Add to List

Share
Given an array A of positive integers, let S be the sum of the digits of the minimal element of A.

Return 0 if S is odd, otherwise return 1.

 

Example 1:

Input: [34,23,1,24,75,33,54,8]
Output: 0
Explanation: 
The minimal element is 1, and the sum of those digits is S = 1 which is odd, so the answer is 0.
Example 2:

Input: [99,77,33,66,55]
Output: 1
Explanation: 
The minimal element is 33, and the sum of those digits is S = 3 + 3 = 6 which is even, so the answer is 1.
 

Constraints:

1 <= A.length <= 100
1 <= A[i] <= 100
Accepted
15,096
Submissions
20,119
Seen this question in a real interview before?

Yes

No
How to find the minimum number in an array?
Loop over the array and compare each one of the numbers.
How to find the sum of digits?
Divide the number consecutively and get their remainder modulus 10. Sum those remainders and return the answer as the problem asks.


