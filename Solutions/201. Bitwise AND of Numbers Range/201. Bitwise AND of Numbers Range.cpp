class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int mv=0;
        while(left!=right){
            left>>=1;
            right>>=1;
            ++mv;
        }
        return left<<mv;
    }
};