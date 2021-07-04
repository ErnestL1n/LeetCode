class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> tmp=nums;
        for(int i=0;i<nums.size();++i)
            nums[i]=tmp[tmp[i]];
        return nums;
    }
};