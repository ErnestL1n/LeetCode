class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size()+1);
        for(int i=digits.size()-1;i>=0;--i){
            if(digits[i]<9){
                ++digits[i];
                return digits;
            }
            digits[i]=0;
        }
        res[0]=1;
        return res;
    }
};