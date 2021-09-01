class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_sz=0;
        for(int i=0;i<nums.size();++i){
            int sz=0;
            for(int k=i;nums[k]>=0;++sz){
                int tmp=nums[k];
                nums[k]=-1;
                k=tmp;
            }
            max_sz=max(max_sz,sz);
        }
        return max_sz;
    }
};