class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=INT_MIN,res=INT_MIN;
        for(auto n:nums){
            curr=max(curr,0)+n;
            res=max(curr,res);
        }
        return res;
    }
};