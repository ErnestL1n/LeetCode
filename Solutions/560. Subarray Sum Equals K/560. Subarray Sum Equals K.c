class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res=0;
        for(auto& n:nums){
            ++m[n];
        }
        for(auto x:m){
            res+=(k==0 and x.second>1) or (k>0 and m.find(k+x.first)!=m.end());
        }
        return res;
    }
};