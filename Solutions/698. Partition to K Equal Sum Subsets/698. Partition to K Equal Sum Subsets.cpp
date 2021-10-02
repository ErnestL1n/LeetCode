// Starting from each subset
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%k!=0)
            return false;
        sort(nums.begin(),nums.end(),[&](int a,int b){return a>b;});
        vector<bool> visited(nums.size());
        return foo(nums,k,0,s/k,0,visited);
    }
    bool foo(vector<int>& nums,int k,int cur_sum,int subset_sum,int begin,vector<bool>& visited){
        if(k==1)
            return true;
        if(cur_sum==subset_sum)
            return foo(nums,k-1,0,subset_sum,0,visited);
        for(int i=begin;i<nums.size();++i){
            if(not visited[i] and cur_sum+nums[i]<=subset_sum){
                visited[i]=true;
                if(foo(nums,k,cur_sum+nums[i],subset_sum,i+1,visited))
                    return true;
                visited[i]=false;
            }
        }
        return false;
    }
};

//another method , Starting from each number
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%k!=0)
            return false;
        sort(nums.begin(),nums.end(),[&](int a,int b){return a>b;});
        vector<int> sums(nums.size());
        return foo(nums,k,s/k,0,sums);
    }
    bool foo(vector<int>& nums,int k,int subset_sum,int begin,vector<int>& sums){
        if(begin==nums.size()){
            for(int i=0;i<k;++i)
                if(sums[i]!=subset_sum)
                    return false;
            return true;
        }
        for(int i=0;i<k;++i){
            if(sums[i]+nums[begin]<=subset_sum){
                sums[i]+=nums[begin];
                if(foo(nums,k,subset_sum,begin+1,sums))
                    return true;
                sums[i]-=nums[begin];
            }
        }
        return false;
    }
};