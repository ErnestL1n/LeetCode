class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int num:nums){
            if(num)
                nums[j++]=num;
        }
        for(;j<nums.size();++j)
            nums[j]=0;
    }
};