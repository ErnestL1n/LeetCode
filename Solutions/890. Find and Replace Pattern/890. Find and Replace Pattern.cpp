class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string p=F(pattern);
        for(auto w:words)
            if(F(w)==p)
                res.push_back(w);
        return res;
    }
    string F(string w){
        vector<int> m(26);
        int cnt=0;
        for(auto c:w)
            if(!m[c-'a'])
                m[c-'a']=cnt++;
        for(int i=0;i<w.size();++i)
            w[i]='a'+m[w[i]-'a'];
        return w;
    }
};
