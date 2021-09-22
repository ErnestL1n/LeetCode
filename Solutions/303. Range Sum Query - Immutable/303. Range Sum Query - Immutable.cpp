//O(n) init and O(n) query solution
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


//O(n) init and O(1) query solution
//using prefix sum
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix=vector<int>(nums.size()+1);
        for(int i=0;i<nums.size();++i)
            prefix[i+1]=prefix[i]+nums[i];
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */