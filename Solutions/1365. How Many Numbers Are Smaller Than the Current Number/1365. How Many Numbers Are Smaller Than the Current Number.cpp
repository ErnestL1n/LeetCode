class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101]={};
        vector<int> res;
        for(auto n:nums)
            ++cnt[n];
        for(int i=1;i<=100;++i)
            cnt[i]+=cnt[i-1];
        for(int n:nums){
            if(n==0)
                res.push_back(0);
            else
                res.push_back(cnt[n-1]);
        }
        return res;
    }
};

//hashmap
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> m;
        auto res=nums;
        sort(begin(res),end(res));
        for(int i=0;i<nums.size();++i)
            if(m.find(res[i])==m.end())
                m[res[i]]=i;
        for(int i=0;i<res.size();++i)
            res[i]=m[nums[i]];
        return res;
    }
};