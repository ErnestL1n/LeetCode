class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt1(26),cnt2(26);
        for(auto& ch:s){
            ++cnt1[ch-'a'];
        }
        for(auto& ch:target){
            ++cnt2[ch-'a'];
        }
        int res=INT_MAX;
        for(auto& ch:target){
            res=min(res,cnt1[ch-'a']/cnt2[ch-'a']);
        }
        return res;
    }
};