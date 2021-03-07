567. Permutation in String
Medium

2224

78

Add to List

Share
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
Accepted
176,813
Submissions
396,479
Seen this question in a real interview before?

Yes

No
Obviously, brute force will result in TLE. Think of something else.
How will you check whether one string is a permutation of another string?
One way is to sort the string and then compare. But, Is there a better way?
If one string is a permutation of another string then they must one common metric. What is that?
Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?
What about hash table? An array of size 26?

Problems

Pick One

Prev
:x
