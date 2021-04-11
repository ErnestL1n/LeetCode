class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res=1;
        for(int n:nums){
            if(n<0)
                res*=-1;
            if(n==0)
                return 0;
        }
        return res;
    }
};

// 1 liner
class Solution {
public:
    int arraySign(vector<int>& nums) {
        return count(begin(nums),end(nums),0)?0:count_if(begin(nums),end(nums),[](int i){return i<0;})%2?-1:1;
    }
};