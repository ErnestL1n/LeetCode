int max(int a,int b){
    return a>b?a:b;
}

int maxDistToClosest(int* seats, int seatsSize){
    int pre=-1,mid=-1,zeros=0;
    for(int i=0;i<seatsSize;++i){
        if(seats[i]==0){
            ++zeros;
        }else{
            if(pre==-1){
                pre=zeros;
            }else{
                mid=max(mid,zeros);
            }
            zeros=0;
        }
    }
    return max(max(pre,zeros),(mid+1)/2);
}