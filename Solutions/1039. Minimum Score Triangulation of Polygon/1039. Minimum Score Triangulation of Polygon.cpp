//top down
class Solution {
public:
    int dp[50][50]={};
    int minScoreTriangulation(vector<int>& values) {
        return foo(values,0,values.size()-1);
    }
    int foo(vector<int>& values,int i,int j){
        if(j-i<=1)
            return 0;
        if(!dp[i][j]){
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;++k)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]);
        }
        return dp[i][j];
    }
};

//buttom up
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        vector<vector<int>> dp(50,vector<int>(50));
        for(int i=A.size()-1;i>=0;--i)
            for(int j=i+1;j<A.size();++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=min(dp[i][j]==0?INT_MAX:dp[i][j],
                                dp[i][k]+dp[k][j]+A[i]*A[k]*A[j]);
        return dp[0][A.size()-1];
    }
};