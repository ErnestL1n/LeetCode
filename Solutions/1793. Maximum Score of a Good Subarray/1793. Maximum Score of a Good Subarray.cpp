class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k,j=k,mini=nums[k],res=nums[k];
        while(i>0 or j<nums.size()-1){
            if((i>0?nums[i-1]:0)<(j<nums.size()-1?nums[j+1]:0))
                mini=min(mini,nums[++j]);
            else
                mini=min(mini,nums[--i]);
            res=max(res,(j-i+1)*mini);
        }
        return res;
    }
};