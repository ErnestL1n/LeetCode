class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(const auto& n:nums)
            ++m[n];
        for(const auto& [k,v]:m)
            if(v>=2)
                return true;
        return false;
    }
};