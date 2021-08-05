class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;++i)
            dp[i][i]=piles[i];
        for(int dis=1;dis<n;++dis)
            for(int begin=0;begin+dis<n;++begin)
                dp[begin][begin+dis]=max(piles[begin]-dp[begin+1][begin+dis],
                                        piles[begin+dis]-dp[begin][begin+dis-1]);
        return dp[0][n-1]>0;
    }
};

//trick : piles.size() must be even && sum(piles)==odd
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};