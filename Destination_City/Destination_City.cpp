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
        return ""; // Note1:
    }
};