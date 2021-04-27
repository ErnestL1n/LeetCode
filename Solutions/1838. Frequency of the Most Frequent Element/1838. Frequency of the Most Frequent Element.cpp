class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int incre=0;
        uint i=0,j=1;
        for(;j<nums.size();++j){
            incre+=(nums[j]-nums[j-1])*(j-i);
            if(incre>k)
                incre-=(nums[j]-nums[i++]);
        }
        return j-i;
    }
};