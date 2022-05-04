// O(NlogN)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==k){
                ++res,++i,--j;
            }else if(nums[i]+nums[j]>k){
                --j;
            }else{
                ++i;
            }
        }
        return res;
    }
};

// O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(auto& n:nums){
            ++um[n];
        }
        int res=0;
        for(auto& [n,cnt]:um){
            if(k-n==n){
                res+=cnt/2;
            }else if(um.count(k-n)){
                int tmp=min(cnt,um[k-n]);
                res+=tmp;
                um[n]-=tmp;
                um[k-n]=tmp;
            }
        }
        return res;
    }
};