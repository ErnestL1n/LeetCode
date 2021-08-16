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
    vector<int> arr;
    NumArray(vector<int>& nums) {
        for(int i=1;i<nums.size();++i)
            nums[i]+=nums[i-1];
        this->arr=nums;
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return this->arr[right];
        return this->arr[right]-this->arr[left-1];
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
