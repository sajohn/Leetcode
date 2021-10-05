5. Longest Palindromic Substring
Medium

13601

805

Add to List

Share
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
Accepted
1,489,764
Submissions
4,764,798
Seen this question in a real interview before?

Yes

No
How can we reuse a previously computed palindrome to compute a larger palindrome?
If “aba” is a palindrome, is “xabax” a palindrome? Similarly is “xabay” a palindrome?
Complexity based hint:
If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.
