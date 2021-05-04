class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> cnt(nums.size()+1);
        for(auto& n:nums)
            cnt[n]=1;
        for(int i=1;i<=nums.size();++i)
            if(!cnt[i])
                res.push_back(i);
        return res;
    }
};


//HashSet
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();++i)
            if(s.find(i)==s.end())
                res.push_back(i);
        return res;
    }
};