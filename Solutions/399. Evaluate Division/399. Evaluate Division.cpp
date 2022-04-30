class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> um;
        for(int i=0;i<eqs.size();++i){
            string st=eqs[i][0],ed=eqs[i][1];
            double ratio=values[i];
            um[st][ed]=ratio;
            um[ed][st]=1/ratio;
        }
        vector<double> res(queries.size());
        for(int i=0;i<queries.size();++i){
            string st=queries[i][0],ed=queries[i][1];
            if(um.count(st)==0 or um.count(ed)==0){
                res[i]=-1;
                continue;
            }
            res[i]=dfs(um,st,ed,unordered_set<string>());
        }
        return res;
    }
    double dfs(unordered_map<string,unordered_map<string,double>>& um,string st,string ed,unordered_set<string> visited){
        if(um[st].count(ed)!=0){
            return um[st][ed];
        }
        visited.insert(st);
        for(auto& road:um[st]){
            if(visited.count(road.first)!=0){
                continue;
            }
            double res=dfs(um,road.first,ed,visited);
            if(res==-1.0){
                continue;
            }
            return res*road.second;
        }
        return -1.0;
    }
};