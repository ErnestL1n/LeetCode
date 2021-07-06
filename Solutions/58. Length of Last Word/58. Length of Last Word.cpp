class Solution {
public:
    int lengthOfLastWord(string s) {
        s+=' ';
        string tmp="";
        for(int i=0;i<s.size();++i){
            if(tmp.size() and s[i]!=' ')
                tmp="";
            while(s[i]!=' ')
                tmp+=s[i++];
        }
        return tmp.size()?tmp.size():0;
    }
};