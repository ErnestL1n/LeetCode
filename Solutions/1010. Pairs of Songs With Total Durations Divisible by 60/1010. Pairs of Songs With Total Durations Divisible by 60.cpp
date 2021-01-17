class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> m(60);
        int res=0;
        for(auto t:time){
            res+=m[(60-t%60)%60];
            ++m[t%60];
        }
        return res;
    }
};