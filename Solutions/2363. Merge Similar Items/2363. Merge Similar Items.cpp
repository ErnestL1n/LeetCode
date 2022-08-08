class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> m;
        for(auto& i:items1){
            m[i[0]]+=i[1];
        }
        for(auto& i:items2){
            m[i[0]]+=i[1];
        }
        vector<vector<int>> res;
        for(auto& [k,v]:m) {
            res.push_back({k,v});
        }
        return res;
    }
};