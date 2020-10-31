class Solution {
public:
    int opA(int n,int start){
        if(start&1)
            return opB(n+1,start-1)^(start-1);
        else
            return opB(n,start);
    }
    int opB(int n,int start){
        if (n % 2 == 0)
            return (n / 2) & 1;
        else
            return ((n / 2) & 1) ^ (start + n - 1);
    }
    int xorOperation(int n, int start) {
        int res=2*opA(n,start/2);
        if(n&start&1)++res;
        return res;
    }
};