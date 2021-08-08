class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string tmp="";
        for(const auto& w:words){
            if(tmp.size()>=s.size())
                break;
            tmp+=w;
        }
        return tmp==s;
    }
};