## [Idea](https://leetcode.com/problems/partition-array-for-maximum-sum/discuss/290863/JavaC%2B%2BPython-DP-O(K)-Space)
  * ```dp[i]``` record the maximum sum we can get considering ```A[0] ~ A[i]```
    To get ```dp[i]```, we will try to change ```k``` last numbers separately to the maximum of them,
    where ```k = 1 to k = BIGK```. 
  * the reason why the length of of ```dp``` is ```n + 1``` rather than ```n``` is as follow :
    * ```curMax = max(curMax, A[i - k + 1])```
    * ```dp[i] = max(dp[i], dp[i - k] + curMax * k)```
    * when calculate the curMax we may need the value of ```nums[0]```, where ```i -k + 1 = 0```  ```i - k = -1```
    * there are no element on the left of the index ```0```, So ```dp[-1] = 0```
