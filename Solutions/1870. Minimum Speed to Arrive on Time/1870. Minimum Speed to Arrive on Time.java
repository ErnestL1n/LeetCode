class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int lo=1,hi=10000000,res=-1,n=dist.length;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            double sum=0;
            for(int i=0;i<n-1;++i)
                sum+=Math.ceil((double)dist[i]/mid);
            sum+=(double)dist[n-1]/mid;
            if(sum>hour)
                lo=mid+1;
            else{
                res=mid;
                hi=mid-1;
            }
        }
        return res;
    }
}