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