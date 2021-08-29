class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int lo=0,hi=k-1,res=INT_MAX;
        while(hi<nums.size()){
            res=min(res,nums[hi]-nums[lo]);
            ++lo,++hi;
        }
        return res;
    }
};