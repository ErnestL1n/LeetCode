class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> m;
        for(int i=0;i<roads.size();++i){
            ++m[roads[i][0]];
            ++m[roads[i][1]];
        }
        priority_queue<pair<int,int>> q;
        for(auto& it:m){
            q.push({it.second,it.first});
        }
        m.clear();
        while(q.size()){
           m.insert({q.top().second,n});
            q.pop();
            --n;
        }
        long long res=0;
        for(int i=0;i<roads.size();++i){
            res+=m[roads[i][0]];
            res+=m[roads[i][1]];
        }
        return res;
    }
};