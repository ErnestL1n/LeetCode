class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo=1,hi=1e7,res=-1,n=dist.size();
        while(lo<=hi){
            double sum=0;
            int mid=(lo+hi)/2;
            for(int i=0;i<n-1;++i)
                sum+=ceil((double)dist[i]/mid);
            sum+=(double)dist[n-1]/mid;
            if(sum>hour)
                lo=mid+1;
            else
                hi=mid-1,res=mid;
        }
        return res;
    }
};