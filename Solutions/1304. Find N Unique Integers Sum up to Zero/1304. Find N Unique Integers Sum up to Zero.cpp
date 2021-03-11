//simple version
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int i=0,j=1;
        if(n%2==1){
            res.push_back(0);
            ++i;
        }
        for(;i<n;i+=2,++j)
            res.push_back(j),res.push_back(-j);
        return res;
    }
};







class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for(int i=0;i<n;++i)
            res.push_back(i*2-n+1);
        return res;
    }
};