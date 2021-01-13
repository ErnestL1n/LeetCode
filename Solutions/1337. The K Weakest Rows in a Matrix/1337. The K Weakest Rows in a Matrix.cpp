class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> s;
        for(int i=0;i<mat.size();++i){
            auto p=accumulate(begin(mat[i]),end(mat[i]),0);
            s.insert({p,i});
        }
        vector<int> res;
        for(auto it=begin(s);k>0;++it,--k)
            res.push_back(it->second);
        return res;
    }
};