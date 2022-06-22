class Solution {
public:
    string greatestLetter(string s) {
        int cnt[128]={};
        for(auto ch:s){
            ++cnt[ch];
        }
        for(auto ch='Z';ch>='A';--ch){
            if(cnt[ch] and cnt[ch+'a'-'A']){
                return string(1,ch);
            }
        }
        return "";
    }
};