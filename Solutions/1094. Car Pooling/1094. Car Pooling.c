

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int cnt[1001]={};
    for(int i=0;i<tripsSize;++i){
        cnt[trips[i][1]]+=trips[i][0],cnt[trips[i][2]]-=trips[i][0];
    }
    for(int i=0;i<1001;++i){
        if(capacity<0){
            return false;
        }
        capacity-=cnt[i];
    }
    return true;
}