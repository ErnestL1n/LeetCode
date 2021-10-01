class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)
            return false;
        int subset_sum=sum/k;
        sort(nums.begin(),nums.end(),[&](int a,int b){return a>b;});
        vector<bool> visited(nums.size());
        return foo(nums,0,0,subset_sum,visited,k);
    }
    bool foo(vector<int>& nums,int begin,int cur_sum,int subset_sum,vector<bool>& visited,int rest_k){
        if(rest_k==1)
            return true;
        if(subset_sum==cur_sum)
            return foo(nums,0,0,subset_sum,visited,rest_k-1);
        for(int i=begin;i<nums.size();++i){
            if(!visited[i] and cur_sum+nums[i]<=subset_sum){
                visited[i]=true;
                if(foo(nums,i+1,cur_sum+nums[i],subset_sum,visited,rest_k))
                    return true;
                visited[i]=false;
            }    
        }
        return false;
    }
};