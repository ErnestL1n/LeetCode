// Top down DP + memo
class Solution {
public:
    int memo[100]={};
    int numDecodings(string s) {
        return dp(s,0);
    }
    int dp(string& s,int i){
        if(i==s.size())
            return 1;
        if(memo[i]!=0)
            return memo[i];
        int res=0;
        if(s[i]!='0')
            res+=dp(s,i+1);
        if(i+1<s.size() and (s[i]=='1' or (s[i]=='2' and s[i+1]<='6')))
            res+=dp(s,i+2);
        return memo[i]=res;
    }
};

// Bottom-up DP
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;--i){
            if(s[i]!='0')
                dp[i]+=dp[i+1];
            if(i+1<n and (s[i]=='1' or (s[i]=='2' and s[i+1]<='6')))
                dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};

// Bottom-up DP (Space Optimized)
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size(),dp=0,dp1=1,dp2=1;
        for(int i=n-1;i>=0;--i){
            if(s[i]!='0')
                dp+=dp1;
            if(i+1<s.size() and (s[i]=='1' or (s[i]=='2' and s[i+1]<='6')))
                dp+=dp2;
            dp2=dp1;
            dp1=dp;
            dp=0;
        }
        return dp1;
    }
};