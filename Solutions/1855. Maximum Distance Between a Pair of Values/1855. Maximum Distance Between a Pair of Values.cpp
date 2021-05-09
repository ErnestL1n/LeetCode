class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        for(int i=0;i<nums1.size();++i){
            int tmp=bs(nums1[i],nums2);
            if(tmp<i)
                continue;
            if(res<tmp-i)
                res=tmp-i;
        }
        return res;
    }
    int bs(int x,vector<int>& nums){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(x>nums[mid])
                r=mid-1;
            else //x>=nums[mid]
                l=mid+1;
        }
        return r;
    }
};