class Solution {
public:
    int dptopdown[102][102];
    int minCostTopDown(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return dfs(cuts,0,cuts.size()-1);
    }
    int dfs(vector<int>& cuts,int i,int j){
        if(j-i<=1)
            return 0;
        if(!dptopdown[i][j]){
            dptopdown[i][j]=INT_MAX;
            for(auto k=i+1;k<j;++k)
                dptopdown[i][j]=min(dptopdown[i][j],
                            cuts[j]-cuts[i]+dfs(cuts,i,k)+dfs(cuts,k,j));
        }
        return dptopdown[i][j];
    }
	
	
	int minCostButtomUp(int n, vector<int>& cuts){
		cuts.push_back(0);
		cuts.push_back(n);
		sort(cuts.begin(),cuts.end());
		int size=cuts.size();
		vector<vector<int>> dp(size,vector<int>(size));
		for(int i=size-1;i>=0;--i)
            for(int j=i+1;j<size;++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=min(dp[i][j]==0?INT_MAX:dp[i][j],
                                cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
        return dp[0][size-1];
	}
};