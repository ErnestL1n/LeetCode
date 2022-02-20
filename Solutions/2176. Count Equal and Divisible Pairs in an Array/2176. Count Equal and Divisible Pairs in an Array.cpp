class Solution {
public:
    int countPairs(vector<int>& nums, int x) {
        unordered_map<int,vector<int>> m;
        int res=0;
        for(int i=0;i<nums.size();++i){
            m[nums[i]].push_back(i);
        }
        for(auto& [k,v]:m){
            for(int i=0;i<v.size();++i){
                for(int j=i+1;j<v.size();++j){
                    if((v[i]*v[j]%x)==0){
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};