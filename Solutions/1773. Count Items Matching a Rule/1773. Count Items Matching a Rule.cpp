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
