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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int type=ruleKey=="type"?0:ruleKey=="color"?1:2;
        return count_if(begin(items),end(items),[=](const auto& i){return i[type]==ruleValue;});
    }
};

//or lamda
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int type=ruleKey=="type"?0:ruleKey=="color"?1:2;
        return count_if(begin(items),end(items),[&](const auto& i){return i[type]==ruleValue;});
    }
};