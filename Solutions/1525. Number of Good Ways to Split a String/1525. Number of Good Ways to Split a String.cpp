class Solution {
public:
    int numSplits(string s) {
        int l[26]={},r[26]={},d_l=0,d_r=0,res=0;
        for(auto& ch:s)
           d_r+=++r[ch-'a']==1;
        for(auto& ch:s){
            d_l+=++l[ch-'a']==1;
            d_r-=--r[ch-'a']==0;
            res+=d_l==d_r;
        }
        return res;
    }
};