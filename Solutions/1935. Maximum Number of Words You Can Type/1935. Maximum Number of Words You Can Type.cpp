class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt[26]={},res=0,flag;
        for(const auto& c:brokenLetters)
            ++cnt[c-'a'];
        text+=' ';
        for(int i=0;i<text.size();++i){
            flag=1;
            while(text[i]!=' '){
                if(cnt[text[i++]-'a']>0)
                    flag=0;
            }
            if(flag)
                ++res;
        }
        return res;
    }
};