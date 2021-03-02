class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int maxcost=0,res=0;
        for(int i=0;i<s.size();++i){
            if(i>0&&s[i]!=s[i-1])
                maxcost=0;
            res+=min(cost[i],maxcost);
            maxcost=max(cost[i],maxcost);
        }
        return res;
    }
};