class Solution {
public:
    int tribonacci(int n) {
        if(n==0){return 0;}
        if(n==1){return 1;}
        if(n==2){return 1;}
        int a=0,b=1,c=1;
        for(int i=3;i<=n;++i){
            int t1=c,t2=b;
            c=a+b+c;
            b=t1;
            a=t2;
        }
        return c;
    }
};