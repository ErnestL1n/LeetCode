class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int tmp=nums[0];
		for(int i=1;i<nums.size();++i) {
			tmp+=nums[i];
			nums[i]=tmp;
		}
		return nums;
    }
};