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





//RMQ 