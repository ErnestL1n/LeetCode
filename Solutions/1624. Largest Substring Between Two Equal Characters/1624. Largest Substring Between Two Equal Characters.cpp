class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int cnt[26]={},res=-1;
        for(int i=0;i<s.size();++i){
            if(cnt[s[i]-'a']==0)
                cnt[s[i]-'a']=i+1;          //trick part,setting it to i+1 if it is 0
            res=max(res,i-cnt[s[i]-'a']);   //i-(i+1) yields -1 if it appeared once
        }
        return res;
    }
};