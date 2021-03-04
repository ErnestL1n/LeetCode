class Solution {
public:
    int maximumScore(vector<int>& a, vector<int>& b) {
        const int n = a.size();
        const int m = b.size();
        static int dp[1010][1010];
        memset(dp, 0, sizeof dp);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int k = i - j;
                dp[i][j] = dp[i+1][j+1] + b[i]*a[j];
                dp[i][j] = max(dp[i][j], dp[i+1][j] + b[i]*a[n-k-1]);
            }
        }
        return dp[0][0];
    }
};


//trick
class Solution {
public:
    int dp[1000][1000]={};
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        return dfs(nums,muls,0,0);
    }
    int dfs(vector<int>& nums,vector<int>&muls,int i,int l){
        if(i>=muls.size())
            return 0;
        if(!dp[i][l]){
            int r=nums.size()-1-(i-l);
            dp[i][l]=max(nums[l]*muls[i]+dfs(nums,muls,i+1,l+1),
                        nums[r]*muls[i]+dfs(nums,muls,i+1,l));
        }
        return dp[i][l];
    }
};

//same as above , don't need to count "r"
class Solution {
public:
    int dp[1000][1000]={};
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        return dfs(nums,muls,0,nums.size()-1,0);
    }
    int dfs(vector<int>& nums,vector<int>& muls,int lo,int hi,int n){
        if(n==muls.size())
            return 0;
        if(!dp[lo][n]){
            dp[lo][n]=max(dfs(nums,muls,lo+1,hi,n+1)+nums[lo]*muls[n],
                  dfs(nums,muls,lo,hi-1,n+1)+nums[hi]*muls[n]);
        }
        return dp[lo][n];
    }
};


