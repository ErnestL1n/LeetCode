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
                dp[i][j]=min(dp[i][j],foo(values,i,k)+foo(values,k,j)+values[i]*values[k]*values[j]);
        }
        return dp[i][j];
    }
};

//buttom up
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(50,vector<int>(50));
        for(int i=values.size()-1;i>=0;--i)
            for(int j=i+1;j<values.size();++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=min(dp[i][j]?dp[i][j]:INT_MAX,
                                dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]);
        return dp[0][values.size()-1];
    }
};