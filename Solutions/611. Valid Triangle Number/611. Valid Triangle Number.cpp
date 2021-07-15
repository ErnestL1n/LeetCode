class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;--i){
            int lo=0,hi=i-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]>nums[i]){
                    res+=hi-lo;
                    --hi;
                }else
                    ++lo;
            }
        }
        return res;
    }
};