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