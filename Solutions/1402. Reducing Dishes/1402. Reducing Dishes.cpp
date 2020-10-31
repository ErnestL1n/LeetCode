class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(begin(s),end(s));
        int res=0,total=0;
        for(int i=s.size()-1;i>=0&&s[i]+total>0;--i){
            total+=s[i];
            res+=total;
        }
        return res;
    }
};