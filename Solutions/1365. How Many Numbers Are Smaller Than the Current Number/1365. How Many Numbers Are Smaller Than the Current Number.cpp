class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101]={};
        vector<int> res;
        for(auto n:nums)
            ++cnt[n];
        for(int i=1;i<=100;++i)
            cnt[i]+=cnt[i-1];
        for(int n:nums){
            if(n==0)
                res.push_back(0);
            else
                res.push_back(cnt[n-1]);
        }
        return res;
    }
};