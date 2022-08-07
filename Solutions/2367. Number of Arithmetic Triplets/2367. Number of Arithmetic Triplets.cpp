class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt[201]={},res=0;
        for(auto& n:nums){
            if(n>=2*diff){
                res+=cnt[n-diff] and cnt[n-2*diff];
            }
            cnt[n]=true;
        }
        return res;
    }
};