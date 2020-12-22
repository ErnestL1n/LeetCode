class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;++i)
            prefix[i+1]=prefix[i]+nums[i];
        for(int i=0;i<n;++i)
            res.push_back(i*nums[i]-prefix[i]+(prefix[n]-prefix[i]-nums[i]*(n-i)));
        return res;
    }
};