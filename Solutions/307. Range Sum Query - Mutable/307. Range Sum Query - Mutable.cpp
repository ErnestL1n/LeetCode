class NumArray {
    #define maxn 30005  // nums.length
    int seg[maxn*4]={}; //children
    inline static int n;
public:
    // segtree index must start from 1
    // otherwise root is 0 and its left child=0*2=0
    // will be invalid
    NumArray(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;++i)
            update(i,nums[i]);
    }
    
    void update(int index, int val,int l=0,int r=n-1,int root=1) {
        if(l==r)
            seg[root]=val;
        else{
            int mid=(l+r)/2,leftson=root*2,rightson=root*2+1;
            if(index<=mid)
                update(index,val,l,mid,leftson);
            else
                update(index,val,mid+1,r,rightson);
            seg[root]=seg[leftson]+seg[rightson];
        }
    }
    
    int sumRange(int left, int right,int st=0,int end=n-1,int root=1) {
        if(left<=st and end<=right)
            return seg[root];
        int mid=(st+end)/2,leftson=root*2,rightson=root*2+1;
        if(right<=mid){
            return sumRange(left,right,st,mid,leftson);
        }
        if(left>mid)
            return sumRange(left,right,mid+1,end,rightson);
        return sumRange(left,right,st,mid,leftson)+sumRange(left,right,mid+1,end,rightson);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */