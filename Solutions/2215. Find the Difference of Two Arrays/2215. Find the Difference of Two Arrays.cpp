class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end()),s2(nums2.begin(),nums2.end());
        vector<vector<int>> res(2);
        for(auto& n:s1){
            if(s2.count(n)==0){
                res[0].push_back(n);
            }
        }
        for(auto& n:s2){
            if(s1.count(n)==0){
                res[1].push_back(n);
            }
        }
        return res;
    }
};