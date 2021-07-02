class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int cnt[10000]={};
        for(const auto& n:nums)
            if(++cnt[n]==2)
                return n;
        return -1;
    }
};


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=2;i<nums.size();++i)
            if(nums[i]==nums[i-1] or nums[i]==nums[i-2])
                return nums[i];
        return nums[0];
    }
};


class Solution {
public:
        int repeatedNTimes(vector<int>& A, int i = 0, int j = 0) {
            while (A[i = rand() % A.size()] != A[j = rand() % A.size()] || i == j);
            return A[i];
    }
};