class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int res=0,l[2]={},r[2]={};
        for(int i=0;i<nums.size();++i)
            r[i%2]+=nums[i];
        for(int i=0;i<nums.size();++i){
            r[i%2]-=nums[i];
            res+=l[0]+r[1]==l[1]+r[0];
            l[i%2]+=nums[i];
            }
        return res;
    }
}; 