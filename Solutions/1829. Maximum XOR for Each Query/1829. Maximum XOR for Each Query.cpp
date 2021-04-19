class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res(nums.size());
        int target=pow(2,maximumBit)-1,curr=0;
        for(int i=0,j=nums.size()-1;i<nums.size();++i,--j){
            curr^=nums[i];
            res[j]=target^curr;
        }
        return res;
    }
};