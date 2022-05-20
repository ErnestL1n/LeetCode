class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[begin++]=nums[i];
            }
        }
        return begin;
    }
};