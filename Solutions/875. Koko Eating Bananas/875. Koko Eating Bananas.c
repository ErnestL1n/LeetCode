

int minEatingSpeed(int* piles, int pilesSize, int h){
    int lo=1,hi=1e9;
    while(lo<hi){
        int mid=lo+hi>>1,sum=0;
        for(int i=0;i<pilesSize;++i){
            sum+=piles[i]/mid;
            if(piles[i]%mid){
                ++sum;
            }
        }
        if(sum>h){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    return lo;
}