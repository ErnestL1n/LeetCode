

bool canPlaceFlowers(int* fw, int sz, int n){
    int cnt=0;
    for(int i=0;i<sz && cnt<n;++i){
        if(fw[i]==0){
            int prev=i==0?0:fw[i-1];
            int next=i==sz-1?0:fw[i+1];
            if(prev==0 && next==0){
                fw[i]=1;
                ++cnt;
            }
        }
    }
    return cnt==n;
}