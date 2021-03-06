// O(N) space 
// O(NK) time
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int BIGK) {
        int n=arr.size();
        vector<int> dp(n+1);
        //dp[0]=1 ,best=max(dp[i-k]+k*maxcurr,best)
        //dp[i]=best
        for(int i=1;i<=n;++i){
            int currMax=0,best=0;
            for(int k=1;k<=BIGK&&k<=i;++k){
                currMax=max(currMax,arr[i-k]);
                best=max(best,dp[i-k]+k*currMax);
            }
            dp[i]=best;
        }
        return dp[n];
    }
};


// O(K) space 
// O(NK) time
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int BIGK) {
        int n=arr.size();
        vector<int> dp(BIGK);
        //dp[0]=1 ,best=max(dp[i-k]+k*maxcurr,best)
        //dp[i]=best
        for(int i=1;i<=n;++i){
            int currMax=0,best=0;
            for(int k=1;k<=BIGK&&k<=i;++k){
                currMax=max(currMax,arr[i-k]);
                best=max(best,dp[(i-k)%BIGK]+k*currMax);
            }
            dp[i%BIGK]=best;
        }
        return dp[n%BIGK];
    }
};