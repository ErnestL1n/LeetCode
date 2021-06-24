class Solution {
public:
    int findPaths(int m, int n, int maxMove, int str, int stc) {
        if(maxMove==0)
            return 0;
        int mod=1e9+7,res=0;
        vector<vector<int>> dp(m,vector<int>(n));
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        dp[str][stc]=1;
        for(int mv=0;mv<maxMove;++mv){
            vector<vector<int>> tmp(m,vector<int>(n));
            for(int r=0;r<m;++r)
                for(int c=0;c<n;++c)
                    for(const auto& [a,b]:dirs){
                        int x=r+a,y=c+b;
                        if(x<0 or x>=m or y<0 or y>=n)
                            res=(res+dp[r][c])%mod;
                        else
                            tmp[x][y]=(tmp[x][y]+dp[r][c])%mod;
                    }
            dp=tmp;
        }
        return res;
    }
};