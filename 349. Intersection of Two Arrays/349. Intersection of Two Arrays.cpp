class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        vector<int> res;
        for(auto& x:nums2)
            if(s.erase(x))
                res.emplace_back(x);
        return res;
    }
};