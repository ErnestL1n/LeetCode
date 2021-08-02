class Solution {
public:
    bool isThree(int n) {
        int d=0;
        for(int i=1;i<=n;++i)
            d+=n%i==0;
        return d==3;
    }
};

//Square of Prime
class Solution {
public:
    bool isThree(int n) {
        set<int> s={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,93,97,101};
        int x=*s.lower_bound(sqrt(n));
        return x*x==n;
    }
};