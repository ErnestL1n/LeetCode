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



// OJ: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
// Author: github.com/lzl124631x
// Time: O(M^2)
// Space: O(M^2)
class Solution {
    int memo[1001][1001] = {};
    int dfs(vector<int> &A, vector<int> &M, int i, int j) {
        if (j == M.size()) return 0;
        if (memo[j][i]) return memo[j][i];
        return memo[j][i] = max(A[i] * M[j] + dfs(A, M, i + 1, j + 1), A[A.size() - j + i - 1] * M[j] + dfs(A, M, i, j + 1));
    }
public:
    int maximumScore(vector<int>& A, vector<int>& M) {
        return dfs(A, M, 0, 0);
    }
};