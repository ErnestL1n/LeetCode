class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size()+1);
        unordered_map<int,int> um;
        for(auto& n:nums){
            ++um[n];
        }
        for(auto& [k,v]:um){
            buckets[v].push_back(k);
        }
        vector<int> res;
        for(int i=nums.size();i>=0 and res.size()<k;--i){
            if(buckets[i].size()){
                res.insert(res.end(),buckets[i].begin(),buckets[i].end());
            }
        }
        return res;
    }
};