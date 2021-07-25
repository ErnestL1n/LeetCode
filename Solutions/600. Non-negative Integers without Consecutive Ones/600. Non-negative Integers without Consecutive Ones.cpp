//TLE version
class Solution {
public:
    int findIntegers(int n) {
        int res=0;
        for(int i=0;i<=n;++i)
            if(foo(i))
                ++res;
        return res;
    }
    bool foo(int n){
        int cnt=0;
        for(int i=31;i>=0;--i){
            int k=n>>i;
            if(k&1)
                ++cnt;
            else
                cnt=0;
            if(cnt>1)
                return false;
        }
        return true;
    }
};

//AC version
class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num&(1<<k)) {
                ans += f[k];
                if (pre_bit) return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};