class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int,int> mp;
        for(auto& n:nums2){
            while(stk.size() and stk.top()<n){
                mp[stk.top()]=n;
                stk.pop();
            }
            stk.push(n);
        }
        vector<int> res;
        for(auto& n:nums1){
            res.push_back(mp.count(n)?mp[n]:-1);
        }
        return res;
    }
};