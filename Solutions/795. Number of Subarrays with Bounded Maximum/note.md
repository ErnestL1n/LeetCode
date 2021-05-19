## [ standard DP solution with explanation ](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117723/Python-standard-DP-solution-with-explanation)

### 
Suppose dp[i] denotes the max number of valid sub-array ending with A[i]. We use following example to illustrate the idea:

A = [2, 1, 4, 2, 3], L = 2, R = 3

if A[i] < L
For example, i = 1. We can only append A[i] to a valid sub-array ending with A[i-1] to create new sub-array. So we have dp[i] = dp[i-1] (for i > 0)

if A[i] > R:
For example, i = 2. No valid sub-array ending with A[i] exist. So we have dp[i] = 0.
We also record the position of the invalid number 4 here as prev.

if L <= A[i] <= R
For example, i = 4. In this case any sub-array starts after the previous invalid number to A[i] (A[prev+1..i], A[prev+2..i]) is a new valid sub-array. So dp[i] += i - prev

Finally the sum of the dp array is the solution. Meanwhile, notice dp[i] only relies on dp[i-1] (and also prev), we can reduce the space complexity to O(1)
