class Solution {
    public int splitArray(int[] nums, int m) {
        int Max=0,sum=0;
        for(int num:nums){
            Max=Math.max(Max,num);
            sum+=num;
        }
        if(m==1)
            return sum;
        int l=Max,r=sum;
        while(l<=r){
            int mid=(l+r)/2;
            if(valid(nums,mid,m))
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
    private boolean valid(int[] nums,int mid,int m){
        int cnt=1,total=0;
        for(int num:nums){
            total+=num;
            if(total>mid){
                total=num;
                ++cnt;
                if(cnt>m)
                    return false;
            }
        }
        return true;
    }
}