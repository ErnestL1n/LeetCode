class Solution {
public:
    int maxFrequency(vector<int>& A, long k) {
        int i = 0, j;
        sort(A.begin(), A.end());
        for (j = 0; j < A.size(); ++j) {
            k += A[j];
            if (k < (long)A[j] * (j - i + 1))
                k -= A[i++];
        }
        return j - i;
    }
};

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int incre=0;
        uint i=0,j=1;
        for(;j<nums.size();++j){
            incre+=(nums[j]-nums[j-1])*(j-i);
            if(incre>k)
                incre-=(nums[j]-nums[i++]);
        }
        return j-i;
    }
};