// RSQ with array
class NumArray {
    inline static int n;
    int* segTree;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        //calloc assign 0 value
        segTree=(int*)calloc(n*4,sizeof(int));
        for(int i=0;i<n;++i)
            update(i,nums[i]);
    }
    
    void update(int idx, int val,int l=0,int r=n-1,int segidx=1) {
        if(l==r)
            segTree[segidx]=val;
        else{
            int mid=(l+r)/2,leftson=segidx*2,rightson=segidx*2+1;
            if(idx<=mid)
                update(idx,val,l,mid,leftson);
            else
                update(idx,val,mid+1,r,rightson);
            segTree[segidx]=segTree[leftson]+segTree[rightson];
        }
    }
    
    int sumRange(int left, int right,int l=0,int r=n-1,int segidx=1) {
        if(left<=l and right>=r)
            return segTree[segidx];
        int mid=(l+r)/2,leftson=segidx*2,rightson=segidx*2+1;
        if(right<=mid)
            return sumRange(left,right,l,mid,leftson);
        if(left>mid)
            return sumRange(left,right,mid+1,r,rightson);
        return sumRange(left,right,l,mid,leftson)+sumRange(left,right,mid+1,r,rightson);
    }
};


//RSQ with Tree construction
class SegmentTree {
    SegmentTree *left, *right;
    int L, R, val;
public:
    SegmentTree(vector<int>& nums, int l, int r): L(l), R(r), left(NULL), right(NULL) {
        build(nums);
    }
    void build(vector<int>& nums) {
        if(L == R) val = nums[L];
        else {
            int mid = (L + R) / 2;
            left = new SegmentTree(nums, L, mid);
            right = new SegmentTree(nums, mid + 1, R);
            val = left -> val + right -> val;
        }
    }
    void update(int i, int new_val) {
        if(L == R) val = new_val;
        else {
            int mid = (L + R) / 2;
            if(i <= mid) left -> update(i, new_val);
            else right -> update(i, new_val);
            val = left -> val + right -> val;
        }
    }
    int sum(int l, int r) {
        if(l > r) return 0;
        if(l == L && r == R) return val;
        int mid = (L + R) / 2;
        return left -> sum(l, min(mid, r)) + right -> sum(max(l, mid + 1), r);
    }
};
class NumArray {
    SegmentTree *tree;
public:
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums, 0, size(nums) - 1);
    }
    
    void update(int index, int val) {
        tree -> update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree -> sum(left, right);
    }
};




//RMQ 


// fenwick tree (Binary index tree)
class NumArray {
public:
    vector<int> nums;
    int* fenwick;
    inline static int n;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
        fenwick=(int*)calloc(n+1,sizeof(int));
    }
    
    void update(int index, int val) {
        
    }
    
    int sumRange(int left, int right) {
        
    }
};