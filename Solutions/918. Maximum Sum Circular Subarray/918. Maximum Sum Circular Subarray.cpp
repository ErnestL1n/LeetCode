class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0,maxSum=nums[0],curMax=0,minSum=nums[0],curMin=0;
        for (int& n:nums) {
            curMax=max(curMax+n,n);
            maxSum=max(maxSum,curMax);
            curMin=min(curMin+n,n);
            minSum=min(minSum,curMin);
            total+=n;
        }
        return maxSum>0?max(maxSum,total-minSum):maxSum;
    }
};