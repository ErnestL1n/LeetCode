class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<=nums[i-1]){
                int tmp=(nums[i-1]-nums[i]+1);
                nums[i]+=tmp;
                res+=tmp;
            }
        }
        return res;
    }
};