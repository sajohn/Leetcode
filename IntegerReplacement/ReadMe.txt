397. Integer Replacement
Medium

//Idea is that if you have a number which is odd 
//Do you want to shift it to make it in a format 100 from 011 
// Or do you want to make it 00 from 01
441

344

Add to List

Share
Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

 

Example 1:

Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1
Example 2:

Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1
Example 3:

Input: n = 4
Output: 2
 

Constraints:

1 <= n <= 231 - 1
Accepted
60,137
Submissions
180,843
Seen this question in a real interview before?

Yes

No
:x
