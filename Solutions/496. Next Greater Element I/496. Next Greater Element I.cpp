class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> stk,res;
        unordered_map<int,int> m;
        for(int n:nums2){
            while(stk.size()&&stk.back()<n){
                m[stk.back()]=n;
                stk.pop_back();
            }
            stk.push_back(n);
        }
        for(int n:nums1)
            res.push_back(m.count(n)?m[n]:-1);
        return res;
    }
};