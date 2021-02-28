class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int best=INT_MAX;
        for(auto base:baseCosts)
            dfs(toppingCosts,base,0,target,best);
        return best;
    }
    void dfs(vector<int>&toppingCosts,int cost,int index,int target,int& best,int max_top=2){
        if(index>=toppingCosts.size()||cost>=target){
            if(abs(cost-target)<abs(best-target))
                best=cost;
            else if(abs(cost-target)==abs(best-target))
                best=min(best,cost);
        }else
            for(int i=0;i<=max_top;++i)
                dfs(toppingCosts,cost+toppingCosts[index]*i,index+1,target,best);
    }
};