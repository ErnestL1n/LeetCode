# [lzl124631x](Ideas arecredit to https://github.com/lzl124631x/LeetCode)

## Solution 1. DP

Let:

	* dp[i][0] be the maximum sum of subarrays that end at A[i] and don't without deletion.
	* dp[i][1] be the maximum sum of subarrays that end at A[i] and have one deletion.
For dp[i][0], we have two options:

	1. Only pick A[i] -- A[i].
	2. Append A[i] to previous best result without deletion -- dp[i - 1][0] + A[i] So dp[i][0] = max(A[i], dp[i - 1][0] + A[i]).
For dp[i][1], we have two options:

	1. treat A[i] as deleted and use the previous best result without deletion -- dp[i - 1][0].
	2. Append A[i] to the previous best result with deletion -- dp[i - 1][1] + A[i].