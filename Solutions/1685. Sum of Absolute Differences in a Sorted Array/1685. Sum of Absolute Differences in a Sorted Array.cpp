class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;++i)
            prefix[i+1]=prefix[i]+nums[i];
        for(int i=0;i<n;++i)
            res.push_back(i*nums[i]-prefix[i]+(prefix[n]-prefix[i]-nums[i]*(n-i)));
        return res;
    }
};




// reduce (extra)space version
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size(),leftsum=0,rightsum=sum(nums);
        vector<int> res;
        for(int i=0;i<n;++i){   
            res.push_back(i*nums[i]-leftsum+(rightsum-nums[i]*(n-i)));
            leftsum+=nums[i];
            rightsum-=nums[i];
        }
        return res;
    }
    int sum(vector<int>& nums){
        int s=0;
        for(int i=0;i<nums.size();++i)
            s+=nums[i];
        return s;
    }
};