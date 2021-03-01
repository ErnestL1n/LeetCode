class Solution {
public:
    int maximumScore(vector<int>& a, vector<int>& b) {
        const int n = a.size();
        const int m = b.size();
        static int dp[1010][1010];
        memset(dp, 0, sizeof dp);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int k = i - j;
                dp[i][j] = dp[i+1][j+1] + b[i]*a[j];
                dp[i][j] = max(dp[i][j], dp[i+1][j] + b[i]*a[n-k-1]);
            }
        }
        return dp[0][0];
    }
};