class Solution {
public:
    string makeGood(string s) {
        string res;
        vector<char> v;
        for(int i=0;i<s.size();++i){
            if(v.size()&&abs(v.back()-s[i])==32)
                v.pop_back();
            else
                v.push_back(s[i]);
        }
        for(auto c:v)res+=c;
        return res;
    }
};