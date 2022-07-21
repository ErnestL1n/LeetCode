class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int cnt[101]={};
        for(auto& n:nums){
            ++cnt[n];
        }
        int pairs=0,left=0;
        for(int& c:cnt){
            pairs+=c/2;
            left+=c%2;
        }
        return {pairs,left};
    }
};