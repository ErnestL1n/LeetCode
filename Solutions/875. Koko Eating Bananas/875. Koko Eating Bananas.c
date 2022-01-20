

int minEatingSpeed(int* piles, int pilesSize, int h){
    int lo=1,hi=1e9;
    while(lo<hi){
        int mid=lo+hi>>1,sum=0;
        for(int i=0;i<pilesSize;++i){
            if(mid>piles[i]){
                sum+=1;
            }else{
                if(piles[i]%mid==0){
                    sum+=piles[i]/mid;
                }else{
                    sum+=1+piles[i]/mid;
                }
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