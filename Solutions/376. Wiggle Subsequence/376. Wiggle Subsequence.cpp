class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<int> up(nums.size()),down(nums.size());
        up[0]=1;
        down[0]=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]){
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }else if(nums[i]<nums[i-1]){
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }else{
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
        }
        return max(down[nums.size()-1],up[nums.size()-1]);
    }
};