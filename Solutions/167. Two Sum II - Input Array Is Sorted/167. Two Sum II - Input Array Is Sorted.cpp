class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int tmp=nums[lo]+nums[hi];
            if(tmp==target){
                return {lo+1,hi+1};
            }
            if(tmp<target){
                ++lo;
            }else{
                --hi;
            }
        }
        return {-1,-1};
    }
};