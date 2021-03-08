class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i=0;i<index.size();++i)
            res.insert(begin(res)+index[i],nums[i]);
        return res;
    }
};