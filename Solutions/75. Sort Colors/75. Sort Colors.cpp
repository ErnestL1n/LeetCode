class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        for(int i=lo;i<=hi;){
            if(nums[i]==2){
                swap(nums[i],nums[hi]);
                --hi;
                continue;
            }
            if(nums[i]==0){
                swap(nums[i],nums[lo]);
                ++lo;
            }
            ++i;
        }
    }
};