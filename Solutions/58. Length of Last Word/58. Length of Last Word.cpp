class Solution {
public:
    int lengthOfLastWord(string s) {
        s.push_back(' ');
        vector<char> tmp;
        for(int i=0;i<s.size();++i){
            if(tmp.size() and s[i]!=' ')
                tmp.clear();
            while(s[i]!=' ')
                tmp.push_back(s[i++]);
        }
        return tmp.size()?tmp.size():0;
    }
};