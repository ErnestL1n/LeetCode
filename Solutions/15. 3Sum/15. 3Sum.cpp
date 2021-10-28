class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i]>0){
                break;
            }
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int lo=i+1,hi=nums.size()-1;
            while(lo<hi){
                if(nums[i]+nums[lo]+nums[hi]==0){
                    res.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo<hi and nums[lo]==nums[lo+1]){
                        ++lo;
                    }    
                    while(lo<hi and nums[hi]==nums[hi-1]){
                        --hi;
                    }
                    ++lo;
                    --hi;
                }else if(nums[i]+nums[lo]+nums[hi]<0){
                    while(lo<hi and nums[lo]==nums[lo+1]){
                        ++lo;
                    }
                    ++lo;
                }else{
                    while(lo<hi and nums[hi]==nums[hi-1]){
                        --hi;
                    }
                    --hi;
                }
            }
        }
        return res;
    }
};


//general solution for N>=2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target=0) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        foo(nums,target,3,0,nums.size()-1,tmp,res);
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