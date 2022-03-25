class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> tmp;
        int n=costs.size()/2,res=0;
        for(auto& cost:costs){
            res+=cost[0];
            tmp.push_back(cost[1]-cost[0]);
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<n;++i){
            res+=tmp[i];
        }
        return res;
    }
};