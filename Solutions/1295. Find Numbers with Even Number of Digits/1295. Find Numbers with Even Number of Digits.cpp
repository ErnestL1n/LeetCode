class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;
        for(auto n:nums)
            if((10<=n and n<=99) or (1000<=n and n<=9999) or n==100000)
                ++res;
        return res;
    }
};

//log10 with bit operation
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;
        for(auto n:nums)
            res+=(int)log10(n)&1;
        return res;
    }
};