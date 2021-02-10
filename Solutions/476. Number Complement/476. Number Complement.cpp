class Solution {
public:
    int findComplement(int num) {
        int n=num;
        int total=1;
        while(n>1){
            n>>=1;
            total=(total<<1)|1;
        }
        return total^num;
    }
};


class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};