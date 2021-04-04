class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k);
        unordered_map<int,unordered_set<int>> m;
        for(auto& log:logs)
            m[log[0]].insert(log[1]);
        for(auto& [k,v]:m)
            ++res[v.size()-1];
        return res;
    }
};