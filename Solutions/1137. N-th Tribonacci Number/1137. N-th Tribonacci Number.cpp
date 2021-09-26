class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1,d;
        if(n<=2)
            return n==0?a:n==1?b:c;
        for(int i=0;i<=n-3;++i){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};