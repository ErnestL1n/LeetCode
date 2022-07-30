class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> cnt(26),tmp(26);
        int i;
        for(string w2:words2){
            tmp=count(w2);
            for(int i=0;i<26;++i){
                cnt[i]=max(cnt[i],tmp[i]);
            }
        }
        vector<string> res;
        for(string w1:words1){
            tmp=count(w1);
            for(i=0;i<26;++i){
                if(tmp[i]<cnt[i]){
                    break;
                }
            }
            if(i==26){
                res.push_back(w1);
            }
        }
        return res;
    }
    vector<int> count(string& word){
        vector<int> cnt(26);
        for(char& c:word){
            ++cnt[c-'a'];
        }
        return cnt;
    }
};