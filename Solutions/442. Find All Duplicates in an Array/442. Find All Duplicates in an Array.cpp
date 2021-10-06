class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> cnt(nums.size()+1);
        vector<int> res;
        for(auto& n:nums)
            ++cnt[n];
        for(int i=1;i<=nums.size();++i)
            if(cnt[i]==2)
                res.push_back(i);
        return res;
    }
};


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> s;
        for(auto& n:nums){
            auto it=s.find(n);
            if(it!=s.end() and ((*it)^n)==0){
                res.push_back(n);
                s.erase(it);
            }else{
                s.insert(n);
            }
        }
        return res;
    }
};