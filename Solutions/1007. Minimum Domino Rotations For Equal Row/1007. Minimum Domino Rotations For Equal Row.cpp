class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int cnt1[7]={},cnt2[7]={},cntsame[7]={};
        int n=tops.size();
        for(int i=0;i<n;++i){
            ++cnt1[tops[i]];
            ++cnt2[bottoms[i]];
            if(tops[i]==bottoms[i]){
                ++cntsame[tops[i]];
            }
        }
        for(int i=1;i<7;++i){
            if(cnt1[i]+cnt2[i]-cntsame[i]==n){
                return n-max(cnt1[i],cnt2[i]);
            }
        }
        return -1;
    }
};