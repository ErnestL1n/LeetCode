

bool winnerSquareGame(int n){
    int* dp=calloc(n+1,sizeof(int));
    for(int i=1;i<=n;++i){
        for(int j=1;j*j<=i;++j){
            if(!dp[i-j*j]){
                dp[i]=1;
            }
        }
    }
    return dp[n];
}