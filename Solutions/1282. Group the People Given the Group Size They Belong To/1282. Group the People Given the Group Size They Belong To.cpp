//using map
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gp) {
        vector<vector<int>> res;
        map<int,vector<int>> m;
        for(int i=0;i<gp.size();++i){
            m[gp[i]].push_back(i);
            if(m[gp[i]].size()==gp[i]){
                res.push_back(m[gp[i]]);
                m.erase(gp[i]);
            }
        }
        return res;
    }
};

//using vector only
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gp) {
        vector<vector<int>> res,group(gp.size()+1);
        for(int i=0;i<gp.size();++i){
            group[gp[i]].push_back(i);
            if(group[gp[i]].size()==gp[i]){
                res.push_back({});
                swap(res.back(),group[gp[i]]);
            }
        }
        return res;
    }
};