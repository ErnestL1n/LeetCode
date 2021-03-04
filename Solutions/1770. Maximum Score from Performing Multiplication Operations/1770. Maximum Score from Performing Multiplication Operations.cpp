//bottom up method 
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        int dp[1001][1001]={};
        for(int n=muls.size()-1;n>=0;--n)
            for(int l=0;l<=n;++l){
                int r=(nums.size()-1-(n-l));
                dp[n][l]=max(dp[n+1][l+1]+nums[l]*muls[n],
                            dp[n+1][l]+nums[r]*muls[n]);
            }
        return dp[0][0];
    }
};

//trick top down method
class Solution {
public:
    int dp[1001][1001]={};
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
    int dp[1001][1001]={};
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


