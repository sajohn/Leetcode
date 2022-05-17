1120. Maximum Average Subtree
Medium

701

28

Add to List

Share
Given the root of a binary tree, return the maximum average value of a subtree of that tree. Answers within 10-5 of the actual answer will be accepted.

A subtree of a tree is any node of that tree plus all its descendants.

The average value of a tree is the sum of its values, divided by the number of nodes.

 

Example 1:


Input: root = [5,6,1]
Output: 6.00000
Explanation: 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
Example 2:

Input: root = [0,null,1]
Output: 1.00000
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 105
Accepted
54,718
Submissions
83,867
Seen this question in a real interview before?

Yes

No
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Amazon
|
10
Can you find the sum of values and the number of nodes for every sub-tree ?
Can you find the sum of values and the number of nodes for a sub-tree given the sum of values and the number of nodes of it's left and right sub-trees ?
Use depth first search to recursively find the solution for the children of a node then use their solutions to compute the current node's solution.

Problems

