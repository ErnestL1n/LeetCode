#define max(a,b) (a>b)?a:b;

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int m=accountsSize,n=*accountsColSize,res=-1;
    for(int i=0;i<m;++i){
        int s=0;
        for(int j=0;j<n;++j){
            s+=accounts[i][j];
        }
        res=max(res,s);
    }
    return res;
}