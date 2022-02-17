class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(),sum=0;
        int curmx=INT_MIN,curmn=INT_MAX;
        int allmx=INT_MIN,allmn=INT_MAX;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            curmx=i>0 and curmx>0?curmx+nums[i]:nums[i];
            curmn=i>0 and curmn<0?curmn+nums[i]:nums[i];
            allmx=max(allmx,curmx);
            allmn=min(allmn,curmn);
        }
        return allmx>0?max(allmx,sum-allmn):allmx;
    }
};