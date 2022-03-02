class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(auto& w:words){
            int ok=1,j;
            for(j=0;j<min(pref.size(),w.size());++j){
                if(w[j]!=pref[j]){
                    ok=0;
                    break;
                }
            }
            if(ok and pref.size()==j){
                ++res;
            }
        }
        return res;
    }
};