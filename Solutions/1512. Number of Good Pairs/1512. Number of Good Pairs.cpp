class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        int cnt[101]={};
        for(auto n:nums)
            ++cnt[n];
        for(int i=1;i<=100;++i)
            res+=cnt[i]*(cnt[i]-1)/2;
        return res;
    }
};