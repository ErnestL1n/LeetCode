class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int res=0;
        for(int i=0;i<nums1.length;++i){
            int tmp=bs(nums1[i],nums2);
            if(tmp<i)
                continue;
            if(res<tmp-i)
                res=tmp-i;
        }
        return res;
    }
    private int bs(int x,int[] nums){
        int l=0,r=nums.length-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(x>nums[mid])
                r=mid-1;
            else //x>=nums[mid]
                l=mid+1;
        }
        return r;
    }
}

class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int i=0,j=0,n1=nums1.length,n2=nums2.length,res=0;
        while(i<n1 && j<n2){
            if(nums1[i]>nums2[j])
                ++i;
            else
                res=Math.max(res,j++-i);
        }
        return res;
    }
}