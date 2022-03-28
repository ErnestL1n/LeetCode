class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+hi>>1;
            if(nums[mid]>nums[hi]){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        int rotate=lo;
        lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+hi>>1;
            int realmid=(mid+rotate)%nums.size();
            if(nums[realmid]==target){
                return realmid;
            }
            if(nums[realmid]<target){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return -1;
    }
};