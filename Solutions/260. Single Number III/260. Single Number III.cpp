class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(const auto& n:nums){
            x^=n;
        }
        int diff=x&(-x),y=0;
        for(const auto& n:nums){
            if((diff&n)!=0){
                y^=n;
            }
        }
        vector<int> res;
        res.push_back(y);
        res.push_back(y^x);
        return res;
    }
};