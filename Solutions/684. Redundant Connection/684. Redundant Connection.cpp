class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ds(1001,-1);
        for(const auto& e:edges){
            int f=e[0],t=e[1];
            if(find(ds,f)==find(ds,t))
                return e;
            else
                ds[find(ds,f)]=find(ds,t);
        }
        return {-1,-1};
    }
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
};class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=-1;
        for(int i=0,j=0;j<nums.size();++j){
            if(nums[j]==1 and j!=nums.size()-1)
                continue;
            if(j==nums.size()-1 and nums[j]!=0){
                res=max(j-i+1,res);
                continue;
            }
            res=max(j-i,res);
            i=j<nums.size()-1?j+1:j;
        }
        return res;
    }
};