class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum=0;
        for(int i=0;i<nums.size();++i)
            sum+=nums[i];
        return sum-*min_element(nums.begin(),nums.end())*nums.size();
    }
};