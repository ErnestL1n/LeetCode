class Solution {
public:
    int kInversePairs(int N, int K) {
        vector<vector<int>> dp(2,vector<int>(1001));
        dp[0][0]=1;
        for(int n=1;n<=N;++n){
            for(int k=0;k<=K;++k){
                dp[n%2][k]=(dp[(n-1)%2][k]+(k>0?dp[n%2][k-1]:0))% 1000000007;
                if(k>=n){
                    dp[n%2][k]=(1000000007+dp[n%2][k]-dp[(n-1)%2][k-n])%1000000007;
                }
            }
        }
        return dp[N%2][K];
    }
};