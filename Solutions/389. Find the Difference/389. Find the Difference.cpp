//xor
class Solution {
public:
    char findTheDifference(string s, string t) {
        char c=t[t.size()-1];
        for(int i=0;i<s.size();++i){
            c^=s[i];
            c^=t[i];
        }
        return c;
    }
};

//count
class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt1[26]={},cnt2[26]={};
        for(int i=0;i<t.size();++i){
            if(i!=s.size()){
                ++cnt1[s[i]-'a'];
            }
            ++cnt2[t[i]-'a'];
        }
        int res;
        for(res=0;res<26;++res){
            if(cnt2[res]-cnt1[res]==1){
                break;
            }
        }
        return res+'a';
    }
};