//Top Down
class Solution {
public:
    int dp[102][102];
    int dfs(vector<int>& cuts,int i,int j){
        if(j-i<=1)
            return 0;
        if(!dp[i][j]){
            dp[i][j]=INT_MAX;
            for(auto k=i+1;k<j;++k){
                dp[i][j]=min(dp[i][j],
                            cuts[j]-cuts[i]+dfs(cuts,i,k)+dfs(cuts,k,j));
            }
            
        }
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));
        return dfs(cuts,0,cuts.size()-1);
    }
};


//Bottom Up
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int size=cuts.size();
        vector<vector<int>> dp(size,vector<int>(size,0));
        for(int i=size-1;i>=0;--i)
            for(int j=i+1;j<size;++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=min(dp[i][j]==0?INT_MAX:dp[i][j],cuts[j]-cuts[i]+
                                dp[i][k]+dp[k][j]);
                    
        return dp[0][size-1];
    }
};