//Recursive approach
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        return fib(n-1)+fib(n-2);
    }
};

//Bottom-Up Approach using Memoization
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        return memo(n);
    }
    int memo(int n){
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;++i)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};

//Top-Down Approach using Memoization
class Solution {
public:
    vector<int> dp;
    int fib(int n) {
        dp=vector<int>(31,-1);
        if(n<=1)
            return n;
        dp[0]=0;
        dp[1]=1;
        return memo(n);
    }
    int memo(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=memo(n-1)+memo(n-2);
        return memo(n);
    }
};

//Iterative Top-Down Approach
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        int cur=0;
        int prev1=1;
        int prev2=1;
        for(int i=3;i<=n;++i){
            cur=prev1+prev2;
            prev2=prev1;
            prev1=cur;
        }
        return cur;
    }
};