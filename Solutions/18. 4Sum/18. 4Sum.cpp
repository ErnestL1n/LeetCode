//general solution for N>=2
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        foo(nums,target,4,0,nums.size()-1,tmp,res);
        return res;
    }
    void foo(vector<int>& nums,int target,int N,int l,int r,vector<int>& tmp,vector<vector<int>>& res){
        if(r-l+1<N or N<2 or target<nums[l]*N or target>nums[r]*N)
            return;
        if(N==2){
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==target){
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    res.push_back(tmp);
                    tmp.pop_back();
                    tmp.pop_back();
                    ++l;
                    while(l<r and nums[l]==nums[l-1])
                        ++l;
                }else if(sum<target){
                    ++l;
                }else{
                    --r;
                }
            }
        }else{
            for(int i=l;i<=r;++i){
                if(i==l or (i>l and nums[i-1]!=nums[i])){
                    tmp.push_back(nums[i]);
                    foo(nums,target-nums[i],N-1,i+1,r,tmp,res);
                    tmp.pop_back();
                }
            }
        }
    }
};

// [1000000000, 1000000000, 1000000000, 1000000000]
// 0
// test case pass
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        foo(nums,target,4,0,nums.size()-1,res,tmp);
        return res;
    }
    void foo(vector<int>& nums,int target,int N,int l,int r,vector<vector<int>>& res,vector<int>& tmp){
        long m_ax=(long)nums[r]*N,m_in=(long)nums[l]*N;
        if(r-l+1<N or N<2 or m_ax<target or m_in>target)
            return;
        if(N==2){
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==target){
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    res.push_back(tmp);
                    ++l;
                    tmp.pop_back();
                    tmp.pop_back();
                    while(l<r and nums[l]==nums[l-1])
                        ++l;
            
                }else if(sum<target){
                    ++l;
                }else{
                    --r;
                }
            }
        }else{
            for(int i=l;i<=r;++i){
                if(i==l or (i>l and nums[i]!=nums[i-1])){
                    tmp.push_back(nums[i]);
                    foo(nums,target-nums[i],N-1,i+1,r,res,tmp);
                    tmp.pop_back();
                }
            }
        }
    }
};

//[2,1,0,-1]
//2
// test case failed