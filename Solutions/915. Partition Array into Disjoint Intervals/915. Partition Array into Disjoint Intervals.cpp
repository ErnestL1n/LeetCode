class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int max_left=nums[0],max_all=nums[0],i,j;
        for(i=0,j=1;j<nums.size();++j){
            if(nums[j]<max_left){
                i=j;
                max_left=max_all;
            }else
                max_all=max(max_all,nums[j]);
        }
        return i+1;
    }
};