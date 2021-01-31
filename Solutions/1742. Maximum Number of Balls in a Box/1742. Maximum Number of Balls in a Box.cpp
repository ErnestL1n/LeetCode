class Solution {
public:
    int countBalls(int lo, int hi) {
        int cnt[46]={};
        for(int i=lo;i<=hi;++i)
            ++cnt[foo(i)];
        return *max_element(begin(cnt),end(cnt));
    }
    int foo(int n){
        int res=0;
        while(n>0){
            res+=n%10;
            n/=10;
        }
        return res;
    }
};