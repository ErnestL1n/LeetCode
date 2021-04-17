class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int cnt=0;
        string tmp;
        s+=" ";
        for(int i=0;i<s.size();++i){
            ++cnt;
            tmp="";
            while(s[i]!=' '){
                tmp+=s[i++];
                if(tmp==searchWord)
                    return cnt;
            }
        }
        return -1;
    }
};