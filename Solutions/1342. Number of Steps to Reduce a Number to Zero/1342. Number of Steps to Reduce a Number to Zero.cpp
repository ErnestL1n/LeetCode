class Solution {
public:
    int numberOfSteps (int num) {
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};

class Solution {
public:
    int numberOfSteps (int num) {
		if(!num) return 0;
        int res = 0;
        while(num) {
            res += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return res - 1;
    }
};