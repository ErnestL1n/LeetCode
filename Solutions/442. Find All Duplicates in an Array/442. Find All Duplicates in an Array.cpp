class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> cnt(nums.size()+1);
        vector<int> res;
        for(auto& n:nums)
            ++cnt[n];
        for(int i=1;i<=nums.size();++i)
            if(cnt[i]==2)
                res.push_back(i);
        return res;
    }
};