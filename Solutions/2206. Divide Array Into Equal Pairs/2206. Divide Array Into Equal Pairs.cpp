class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto& n:nums){
            ++um[n];
        }
        for(auto& [k,v]:um){
            if(v%2!=0){
                return false;
            }
        }
        return true;
    }
};