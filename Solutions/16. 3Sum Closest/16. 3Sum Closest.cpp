class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[nums.size()-1];
        for(int i=0;i<nums.size()-2;++i){
            int lo=i+1,hi=nums.size()-1;
            while(lo<hi){
                int s=nums[lo]+nums[hi]+nums[i];
                if(s>target){
                    --hi;
                }else{
                    ++lo;
                }
                if(abs(s-target)<abs(res-target))
                    res=s;
            }
        }
        return res;
    }
};