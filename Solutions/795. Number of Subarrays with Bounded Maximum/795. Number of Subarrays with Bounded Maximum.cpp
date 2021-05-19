class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        int res=0,prev=-1,dp=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<L and i>0){
                res+=dp;
            }
            if(nums[i]>R){
                dp=0;
                prev=i;
            }
            if(L<=nums[i] and nums[i]<=R){
                dp=i-prev;
                res+=dp;
            }
        }
        return res;
    }
};