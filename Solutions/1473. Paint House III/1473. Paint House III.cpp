class Solution {
public:
    int dp[101][101][21]={};
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res=dfs(houses,cost,0,target,0);
        return res>1000000?-1:res;
    }
    int dfs(vector<int>& houses,vector<vector<int>>& cost,int i,int target,int last_color){
        if(i>=houses.size() or target<0){
            return target==0?target:1000001;
        }
        if(houses[i]!=0){
            return dfs(houses,cost,i+1,target-(last_color!=houses[i]),houses[i]);
        }
        if(dp[i][target][last_color]){
            return dp[i][target][last_color];
        }
        int res=1000001;
        for (int color=1;color<=cost[i].size();++color) {
            res=min(res,cost[i][color-1]+dfs(houses,cost,i+1,target-(last_color!=color),color));
        }            
        return dp[i][target][last_color]=res;
    }
};