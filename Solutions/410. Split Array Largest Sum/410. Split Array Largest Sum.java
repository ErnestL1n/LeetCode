class Solution {
    public int splitArray(int[] nums, int m) {
        int MAX=-1,sum=0;
        for(int n:nums){
            MAX=Math.max(MAX,n);
            sum+=n;
        }
        if(m==1){
            return sum;
        }
        int lo=MAX,hi=sum;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(count(nums,m,mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
    private boolean count(int[] nums,int m,int target_sum){
        int cnt=1,sum=0;
        for(int n:nums){
            sum+=n;
            if(sum>target_sum){
                sum=n;
                if(++cnt>m){
                    return false;
                }
            }
        }
        return true;
    }
}
