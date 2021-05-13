class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=nums[nums.size()-1]-nums[0],right=nums[nums.size()-1]-k,left=nums[0]+k;
        for(int i=0;i<nums.size()-1;++i){
            int m_ax=max(right,nums[i]+k);
            int m_in=min(left,nums[i+1]-k);
            res=min(res,m_ax-m_in);
        }
        return res;
    }
};