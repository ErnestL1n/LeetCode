class Solution {
public:
    string defangIPaddr(string s) {
        string res="";
        for(int i=0;i<s.size();++i){
            if(s[i]=='.')
                res+="[.]";
            else
                res+=s[i];
        }
        return res;
    }
};