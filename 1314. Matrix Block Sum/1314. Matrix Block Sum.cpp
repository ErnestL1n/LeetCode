/*
@credit to rock (https://leetcode.com/rock/)

Note: (key!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
    1.rangeSum[i + 1][j + 1] corresponds to cell (i, j);
    2.rangeSum[0][j] and rangeSum[i][0] are all dummy values, which are used for the convenience of computation of DP state transmission formula.


1.

To calculate rangeSum, the ideas are as below - credit to @haoel

+-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
|     | |       |     |        |     |     |     |         |     |     |        |
|     | |       |     |        |     |     |     |         |     |     |        |
+-----+-+       |     +--------+     |     |     |         |     +-----+        |
|     | |       |  =  |              |  +  |     |         |  -  |              | + mat[i][j]
+-----+-+       |     |              |     +-----+         |     |              |
|               |     |              |     |               |     |              |
|               |     |              |     |               |     |              |
+---------------+     +--------------+     +---------------+     +--------------+

rangeSum[i+1][j+1] =  rangeSum[i][j+1] + rangeSum[i+1][j]    -   rangeSum[i][j]   + mat[i][j]

2.

So, we use the same idea to find the specific block's sum. - credit to @haoel

+---------------+   +--------------+   +---------------+   +--------------+   +--------------+
|               |   |         |    |   |   |           |   |         |    |   |   |          |
|   (r1,c1)     |   |         |    |   |   |           |   |         |    |   |   |          |
|   +------+    |   |         |    |   |   |           |   +---------+    |   +---+          |
|   |      |    | = |         |    | - |   |           | - |      (r1,c2) | + |   (r1,c1)    |
|   |      |    |   |         |    |   |   |           |   |              |   |              |
|   +------+    |   +---------+    |   +---+           |   |              |   |              |
|        (r2,c2)|   |       (r2,c2)|   |   (r2,c1)     |   |              |   |              |
+---------------+   +--------------+   +---------------+   +--------------+   +--------------+



Analysis:

Time & space: O(m * n).

*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]+mat[i][j];
        vector<vector<int>> res(m,vector<int>(n));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                int r_lo=max(0,i-K),c_lo=max(0,j-K),r_hi=min(m,i+K+1),c_hi=min(n,j+K+1);
                res[i][j]=dp[r_hi][c_hi]-dp[r_hi][c_lo]-dp[r_lo][c_hi]+dp[r_lo][c_lo];
            }
        return res;
    }
};
