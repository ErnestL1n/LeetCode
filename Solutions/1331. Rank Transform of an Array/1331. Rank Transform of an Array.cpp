class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res(arr);
        unordered_map<int,int> rk;
        sort(res.begin(),res.end());
        for(auto& a:res)
            rk.emplace(a,rk.size()+1);
        for(int i=0;i<arr.size();++i)
            res[i]=rk[arr[i]];
        return res;
    }
};