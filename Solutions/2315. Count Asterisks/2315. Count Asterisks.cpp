class Solution {
public:
    int countAsterisks(string s) {
        int res=0,pipes=0;
        for(auto& c:s){
            pipes+=c=='|';
            res+=c=='*' and pipes%2==0;
        }
        return res;
    }
};