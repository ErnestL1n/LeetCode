class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+9487);
        dp[0]=0;
        for(int i=1;i<=amount;++i)
            for(const auto& c:coins)
                if(i>=c)
                    dp[i]=min(dp[i],1+dp[i-c]);
        return dp[amount]==amount+9487?-1:dp[amount];
    }
};