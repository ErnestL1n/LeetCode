class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> str;
        string tmp="";
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){
                str.push_back(tmp);
                tmp="";
                continue;
            }
            tmp+=s[i];
            if(i==s.size()-1)
                str.push_back(tmp);
        }
        if(str.size()!=p.size())
            return false;
        unordered_map<char,string> m;
        for(int i=0;i<p.size();++i){
            if(m.find(p[i])==m.end()){
                m[p[i]]=str[i];
                continue;
            }
            if(m[p[i]]!=str[i])
                return false;
        }
        unordered_map<string,char> k;
        for(int i=0;i<str.size();++i){
            if(k.find(str[i])==k.end()){
                k[str[i]]=p[i];
                continue;
            }
            if(k[str[i]]!=p[i])
                return false;
        } 
        return true;
    }
};