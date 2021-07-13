class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i]>0)
                break;
            if(i>0 and nums[i-1]==nums[i])
                continue;
            int lo=i+1,hi=nums.size()-1,target=-nums[i];
            while(lo<hi){
                if(nums[lo]+nums[hi]==target){
                    res.push_back({nums[lo],nums[hi],nums[i]});
                    ++lo;--hi;
                    while(lo<hi and nums[lo]==nums[lo-1])++lo;
                    while(lo<hi and nums[hi]==nums[hi+1])--hi;
                }else if(nums[lo]+nums[hi]<target)
                    ++lo;
                else{
                    --hi;
                }
            }
        }
        return res;
    }
};