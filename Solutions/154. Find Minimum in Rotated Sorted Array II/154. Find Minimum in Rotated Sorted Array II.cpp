class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>nums[hi])
                lo=mid+1;
            else if(nums[mid]<nums[lo])
                hi=mid;
            else{
                if(nums[hi]<nums[hi-1]){
                    lo=hi;
                    break;
                }
                --hi;
            }
        }
        return nums[lo];
    }
};