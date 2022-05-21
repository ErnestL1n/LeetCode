class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> cnt(1001),res;
        for(auto& arr:nums){
            for(int& n:arr){
                ++cnt[n];
            }
        }
        for(int i=0;i<cnt.size();++i){
            if(cnt[i]==nums.size()){
                res.push_back(i);
            }
        }
        return res;
    }
};