class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        for(int i=0,l=0,h=S.size();i<=S.size();++i)
            res.push_back(i==S.size()||S[i]=='I'?l++:h--);
        return res;
    }
};