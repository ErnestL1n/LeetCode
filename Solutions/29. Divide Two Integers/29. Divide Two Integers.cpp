class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==-1){
            return INT_MAX;
        }
        long dvd=labs(dividend),dvs=labs(divisor),res=0;
        int sign=dividend>0^divisor>0?-1:1;
        while(dvd>=dvs){
            long tmp=dvs,m=1;
            while(tmp<<1<=dvd){
                tmp<<=1;
                m<<=1;
            }
            dvd-=tmp;
            res+=m;
        }
        return sign*res;
    }
};