class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res=0;
        for(const auto& p:patterns)
            res+=word.find(p)!=string::npos;
        return res;
    }
};

// 1 liner
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        return count_if(begin(patterns),end(patterns),[&](const auto& p){return word.find(p)!=string::npos;});
    }
};