class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        return *min_element(begin(nums),end(nums),[&](int n1,int n2){
            return abs(n1)<abs(n2) or (abs(n1)==abs(n2) and n1>n2);
        });
    }
};