class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int,vector<int>> m;
        for(auto& a:adj){
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        vector<int> res;
        for(auto& x:m){
            if(x.second.size()==1){
                res.push_back(x.first);
                res.push_back(x.second[0]);
                break;
            }
        }
        while(res.size()!=adj.size()+1){
            auto tail=res.back(),prev=res[res.size()-2];
            auto& next=m[tail];
            if(next[0]!=prev)
                res.push_back(next[0]);
            else
                res.push_back(next[1]);
        }
        return res;
    }
};