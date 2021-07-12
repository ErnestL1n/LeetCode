// O(n^3) BF
class Solution {
public:
    int countTriples(int n) {
        int res=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    res+=i*i+j*j==k*k;
        return res;
    }
};

// O(n^2)
class Solution {
public:
    int countTriples(int n) {
        vector<bool> squares(n*n+1);
        for(int i=1;i<=n;++i)
            squares[i*i]=true;
        int res=0;
        for(int i=1;i<=n;++i)
            for(int j=i;i*i+j*j<=n*n;++j)
                res+=2*squares[i*i+j*j];
        return res;
    }
};