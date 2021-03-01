## DP similar to [Matrix Chain Multiplication](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)
### Complexity : ```Time O(N^3/K) Space O(N^2)```
### ```dp[i][j]``` means the minimum cost needed to merge ```stones[i] ~ stones[j]```
#### Why ```dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]) && i<=k<j```
  * The length can't overlap , if we do it like ```dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]) && i<=k<=j``` it may happen like this
    * ![](https://i.imgur.com/MtitVz2.png)
  * Which doesn't make sense for dp[i][j] 's meaning : the minimum cost needed to merge ```stones[i] ~ stones[j]```
### Why ```k(lower case)``` jump at step ```K(upper case) - 1```
  * We can merge ```K``` piles into one pile,
  * we can't merge ```K + 1``` piles into one pile.
  * We can merge ```K + K - 1``` piles into on pile,
  * We can merge ```K + (K - 1) * steps``` piles into one pile.
  * Or , when ```stones[i]``` is merged, it must be merged with multiple of ```(K-1)``` other stones
