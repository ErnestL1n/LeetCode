class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i=0,j=1;i<nums.size();i+=2,j+=2)
            while(nums[i]--)
                res.push_back(nums[j]);
        return res;
    }
};