class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int cur=0,res=INT_MAX;
        for(const auto& n:nums){
            cur+=n;
            res=min(res,cur);
        }
        return res<0?-(res-1):1;
    }
};