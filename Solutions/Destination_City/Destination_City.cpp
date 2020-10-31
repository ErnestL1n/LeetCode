class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> degreeMap;        
        for(auto& e: paths){
            degreeMap[e[0]] += 1;
            degreeMap[e[1]] += 0;
        }
        
        for (auto& [k, v]: degreeMap)
            if (v == 0)
                return k;
        return ""; 
    }
};
/* above one is better
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> seen;
        for(auto& pa:paths)
            seen[pa[0]]=pa[1];
        for(auto& [k,v]:seen)
            if(seen[v]=="")
                return v;
        return "";
    }
};
*/