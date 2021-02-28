class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int type=0,res=0;
        if(ruleKey=="color")
            type=1;
        else if(ruleKey=="name")
            type=2;
        for(auto& it:items)
            if(it[type]==ruleValue)
                ++res;
        return res;
    }
};


// 2 liner
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string key, string val) {
        int idx = key == "type" ? 0 : key == "color" ? 1 : 2;
        return count_if(begin(items), end(items), [&](const auto &i) { return i[idx] == val; });
    }
};