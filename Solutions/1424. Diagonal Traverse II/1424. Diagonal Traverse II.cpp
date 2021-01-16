class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        unordered_map<int,vector<int>> m;
        int diaN=0;
        for(int i=0;i<nums.size();++i)
            for(int j=0;j<nums[i].size();++j){
                m[i+j].push_back(nums[i][j]);
                diaN=max(diaN,i+j);
            }
        for(int i=0;i<=diaN;++i)
            for(auto it=m[i].rbegin();it!=m[i].rend();++it)
                res.push_back(*it);
        return res;
    }
};
