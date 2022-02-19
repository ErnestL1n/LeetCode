class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt=0,res=0,n=nums.size();
        unordered_map<int,int> m;
        m[0]=0;
        // key => y-axis , val => x-axis
        for(int i=0;i<n;++i){
            if(nums[i]==0){
                --cnt;
            }else{
                ++cnt;
            }
            if(m.find(cnt)!=m.end()){
                res=max(res,i+1-m[cnt]);
            }else{
                m[cnt]=i+1;
            }
        }
        return res;
    }
};