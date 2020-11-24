class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(2));
        dp[0][0]=arr[0];
        int res=arr[0];
        for(int i=1;i<arr.size();++i){
            dp[i][0]=max(arr[i],dp[i-1][0]+arr[i]);
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]+arr[i]);
            res=max({res,dp[i][0],dp[i][1]});
        }
        return res;
    }
};




class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int skip=0,n=arr.size(),pick=arr[0],res=arr[0];
        for(int i=1;i<n;++i){
            int p=max(pick+arr[i],arr[i]),s=max(pick,skip+arr[i]);
            pick=p;
            skip=s;
            res=max({p,s,res});
        }
        return res;
    }
};