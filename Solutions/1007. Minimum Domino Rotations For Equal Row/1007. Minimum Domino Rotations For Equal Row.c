#define max(a,b) (a>b?a:b)

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
    // topsSize==n
    int *cnt1=calloc(7,sizeof(int)),*cnt2=calloc(7,sizeof(int)),*cntsame=calloc(7,sizeof(int));
    for(int i=0;i<topsSize;++i){
        ++cnt1[tops[i]];
        ++cnt2[bottoms[i]];
        if(tops[i]==bottoms[i]){
            ++cntsame[tops[i]];
        }
    }
    for(int i=1;i<7;++i){
        if(cnt1[i]+cnt2[i]-cntsame[i]==topsSize){
            return topsSize-max(cnt1[i],cnt2[i]);
        }
    }
    return -1;
}