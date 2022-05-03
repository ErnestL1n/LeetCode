class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //initialize end = -2 is a smart move. we can always return end - beg + 1
        //no need to check if the array is already sorted.
        int n=nums.size(),st=-1,ed=-2;
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<nums.size();++i){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[n-i-1]);
            if(nums[i]<mx){
                ed=i;
            }
            if(nums[n-i-1]>mn){
                st=n-i-1;
            }
        }
        return ed-st+1;
    }
};