class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        this->arr=nums;
    }
    
    int sumRange(int left, int right) {
        return accumulate(begin(arr)+left,begin(arr)+right+1,0,[this](int s,const int& n){return s+n;});
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */