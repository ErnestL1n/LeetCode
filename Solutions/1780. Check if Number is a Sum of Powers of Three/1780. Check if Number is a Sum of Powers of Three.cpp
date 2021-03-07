//trick , Decimal to 3 ternary
class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(;n;n/=3)
            if(n%3==2)
                return false;
        return true;
    }
};

//back tracking
class Solution {
public:
    bool checkPowersOfThree(int n,int p=1) {
        if(n==0)
            return true;
        if(n<p)
            return false;
        return checkPowersOfThree(n,3*p) || checkPowersOfThree(n-p,3*p);
    }
};


//subset sum method , not recommended
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> s;
        int tmp=1;
        for(;tmp<=n;tmp*=3)
            s.push_back(tmp);
        return subset(s,s.size(),n);
    }
    bool subset(vector<int>& s,int n,int sum){
        if(sum==0)
            return true;
        if(n==0)
            return false;
        if(s[n-1]>sum)
            return subset(s,n-1,sum);
        return subset(s,n-1,sum) || subset(s,n-1,sum-s[n-1]);
    }
};

//buttom up memorization yielded TLE
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> s;
        int tmp=1;
        for(;tmp<=n;tmp*=3)
            s.push_back(tmp);
        return subsetsum(s,s.size(),n);
    }
    bool subsetsum(vector<int>& s,int n,int sum){
        bool subset[n+1][sum+1];
        for(int i=0;i<=n;++i)
            subset[i][0]=true;
        for(int i=1;i<=sum;++i)
            subset[0][i]=false;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=sum;++j){
                if(j<s[i-1])
                    subset[i][j]=subset[i-1][j];
                if(j>=s[i-1])
                    subset[i][j]=subset[i-1][j] ||subset[i-1][j-s[i-1]];
            }
        return subset[n][sum];
    }
};