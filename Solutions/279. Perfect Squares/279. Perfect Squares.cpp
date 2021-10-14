//normal dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j*j<=i;++j){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};

//static vector dp
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        while(dp.size()<=n){
            int sz=dp.size(),tmp=INT_MAX;
            for(int i=1;i*i<=sz;++i){
                tmp=min(tmp,dp[sz-i*i]+1);
            }
            dp.push_back(tmp);
        }
        return dp[n];
    }
};