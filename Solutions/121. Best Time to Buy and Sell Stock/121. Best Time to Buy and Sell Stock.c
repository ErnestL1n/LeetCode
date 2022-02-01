#define max(a,b) (a>b?a:b)

int maxProfit(int* prices, int pricesSize){
    int tmp=0,res=0;
    for(int i=1;i<pricesSize;++i){
        tmp=max(0,tmp+prices[i]-prices[i-1]);
        res=max(res,tmp);
    }
    return res;
}