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

//two pointers solution
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0)
            return false;
        int lo=0,hi=sqrt(c);
        while(lo<=hi){
            long cur=lo*lo+(long)hi*hi;
            if(cur<c)
                ++lo;
            else if(cur>c)
                --hi;
            else
                return true;
            
        }
        return false;
    }
};