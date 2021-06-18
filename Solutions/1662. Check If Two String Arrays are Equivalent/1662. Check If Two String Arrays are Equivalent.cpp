class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string tmp="";
        int i=0;
        for(const auto& w:word1)
            for(const auto& c:w)
                tmp+=c;
        for(const auto& w:word2)
            for(const auto& c:w)
                if(c!=tmp[i++])
                    return false;
        return true;
    }
};