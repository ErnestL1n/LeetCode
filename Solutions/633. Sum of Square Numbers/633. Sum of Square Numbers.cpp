class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> s;
        for(int i=0;i<=sqrt(c);++i){
            s.insert(i*i);
            if(s.find(c-i*i)!=s.end())
                return true;
        }
        return false;
    }
};