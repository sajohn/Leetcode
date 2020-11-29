1015. Smallest Integer Divisible by K
Medium

341

372

Add to List

Share
Given a positive integer K, you need to find the length of the smallest positive integer N such that N is divisible by K, and N only contains the digit 1.

Return the length of N. If there is no such N, return -1.

Note: N may not fit in a 64-bit signed integer.

 

Example 1:

Input: K = 1
Output: 1
Explanation: The smallest answer is N = 1, which has length 1.
Example 2:

Input: K = 2
Output: -1
Explanation: There is no such positive integer N divisible by 2.
Example 3:

Input: K = 3
Output: 3
Explanation: The smallest answer is N = 111, which has length 3.
 

Constraints:

1 <= K <= 105
Accepted
25,883
Submissions
62,178
Seen this question in a real interview before?

Yes

No
11111 = 1111 * 10 + 1 We only need to store remainders modulo K.
If we never get a remainder of 0, why would that happen, and how would we know that

Solution
Overview
It's an interesting problem that requires a little observation and insight. It's recommended to try a few numbers to find out some regular patterns. Below, we will discuss a simple approach to solve this problem.

Approach 1: Checking Loop
Intuition

We need to do two things:

check if the required number N exists.
find out length(N).
The second one is easy: we only need to keep multiplying N by 10 and adding 1 until N%K==0. However, since N might overflow, we need to use the remainder. The pseudo-code is as below:

remainder = 1
length_N = 1

while remainder%K != 0
    N = remainder*10 + 1
    remainder = N%K
    length_N += 1

return length_N
Since the remainder and N have the same remainder of K, it OK to use remainder instead of N.

Now, the only problem is how to check whether the required number N exists.

Notice that if N does not exist, this while-loop will continue endlessly. However, the possible values of remainder are limited -- ranging from 0 to K-1. Therefore, if the while-loop continues forever, the remainder repeats. Also, if remainder repeats, then it gets into a loop. Hence, the while-loop is endless if and only if the remainder repeats.

In this case, we can check if the remainder repeats to check if the while-loop is endless:

remainder = 1
length_N = 1

seen_remainders = set()

while remainder%K != 0
    N = remainder*10 + 1
    remainder = N%K
    length_N += 1

    if remainder in seen_remainders
        return -1
    else
        seen_remainders.add(remainder)

return length_N
Now we have an algorithm that can solve the problem.

Furthermore, we can improve this algorithm with Pigeonhole Principle. Recall that the number of possible values of remainder (ranging from 0 to K-1) is limited, and in fact, the number is K. As a result, if the while-loop continues more than K times, and haven't stopped, then we can conclude that remainder repeats -- you can not have more than K different remainder.

Hence, if N exists, the while-loop must return length_N in the first K loops. Otherwise, it goes into an infinite loop.

Therefore, we can just run the while-loop K times, and return -1 if not stopped.

Algorithm

We just run the while-loop K times, check if the remainder is 0, and return -1 if not stopped.

Note: After reading the Algorithm part, it is recommended to try writing the code on your own before reading the solution code.


There are a few interesting points worth pointing out in the code above:

We initialize remainder to 0, not 1, to keep code consistency because in the first loop the remainder changes to 1. You can also initialize it as 1, but it requires a little change in code.
We only run the loop K times at most, not K+1. This is because if it does not stop in the previous K loop, it will continue the K+1-th iteration, which must have repeated remainder. Therefore, it is not necessary to check the K+1-th iteration.
Also, note that 111...111 can never be divided by 2 or 5 because its last digit is never an even number or 5. You can just return -1 if you find that 2 or 5 is a factor of K.

Complexity Analysis

Time Complexity : \mathcal{O}(K)O(K) since we at most run the loop \mathcal{O}(K)O(K) times.

Space Complexity : \mathcal{O}(1)O(1) since we only use three ints: K, remainder, and length_N.:x
?
