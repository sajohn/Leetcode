1541. Minimum Insertions to Balance a Parentheses String
Medium

642

138

Add to List

Share
Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

 

Example 1:

Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.
Example 2:

Input: s = "())"
Output: 0
Explanation: The string is already balanced.
Example 3:

Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.
 

Constraints:

1 <= s.length <= 105
s consists of '(' and ')' only.
Accepted
29,264
Submissions
59,225
Seen this question in a real interview before?

Yes

No
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Facebook
|
4

Microsoft
|
4
Use a stack to keep opening brackets. If you face single closing ')' add 1 to the answer and consider it as '))'.
If you have '))' with empty stack, add 1 to the answer, If after finishing you have x opening remaining in the stack, add 2x to the answer.

Problems

