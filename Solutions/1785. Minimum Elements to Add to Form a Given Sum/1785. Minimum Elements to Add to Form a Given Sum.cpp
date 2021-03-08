class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long res=0,sum=0;
        for(auto n:nums)
            sum+=n;
        long long diff=abs(goal-sum);
        res+=diff/limit;
        if(diff%limit)
            ++res;
        return res;
    }
};