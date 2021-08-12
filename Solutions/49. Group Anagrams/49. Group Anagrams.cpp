class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(const auto& s:strs){
            auto tmp=s;
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& [k,v]:m)
            res.push_back(v);
        return res;
    }
};

// since the string only contains lower-case alphabets, we can sort them using counting sort to improve the time complexity.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(const auto& s:strs){
            auto tmp=countingSort(s);
            m[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& [k,v]:m)
            res.push_back(v);
        return res;
    }
    string countingSort(string s){
        int cnt[26]={};
        for(const auto& c:s)
            ++cnt[c-'a'];
        string tmp="";
        for(int i=0;i<26;++i){
            // string (size_t n, char c);
            // Fills the string with n consecutive copies of character c.
            tmp+=string(cnt[i],'a'+i);
        }
        return tmp;
    }
};