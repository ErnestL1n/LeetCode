class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int n=s.size();
        unordered_map<char,int> cnts;
        for(int i=0;i<n;++i){
            ++cnts[s[i]],--cnts[t[i]];
        }
        for(const auto& cnt:cnts)
            if(cnt.second)
                return false;
        return true;
    }
};