class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res=INT_MIN,poslen=0,neglen=0;
        for(int& n:nums){
            if(n==0){
                poslen=0,neglen=0;
            }else if(n>0){
                ++poslen;
                neglen=neglen==0?0:++neglen;
            }else{
                int tmp=poslen;
                poslen=neglen==0?0:++neglen;
                neglen=tmp+1;
            }
            res=max(res,poslen);
        }
        return res;
    }
};

// elements      :   9    5    8    2    -6    4    -3    0    2    -5    15    10    -7    9    -2
// positive_len  :   1    2    3    4     0    1     7    0    1     0     1     2     5    6     5
// negative_len  :   0    0    0    0     5    6     2    0    0     2     3     4     3    4     7