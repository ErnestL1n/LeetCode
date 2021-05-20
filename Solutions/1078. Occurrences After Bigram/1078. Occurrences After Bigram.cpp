class Solution {
public:
    vector<string> findOcurrences(string s, string first, string second) {
        vector<string> res;
        vector<string> tmp;
        s+=' ';
        for(int i=0;i<s.size();++i){
            string t="";
            while(s[i]!=' ')
                t+=s[i++];
            tmp.push_back(t);
        }
        for(int i=0;i<tmp.size()-2;++i)
            if(tmp[i]==first and tmp[i+1]==second)
                res.push_back(tmp[i+2]);
        return res;
    }
};