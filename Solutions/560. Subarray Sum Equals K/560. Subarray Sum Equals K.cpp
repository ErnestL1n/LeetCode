//TLE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),res=0;
        vector<int> prefix(n+1);
        for(int i=0;i<n;++i){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                res+=prefix[j+1]-prefix[i]==k;
            }
        }
        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,res=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()){
                res+=m[sum-k];
            }
            m[sum]+=1;
        }
        return res;
    }
};