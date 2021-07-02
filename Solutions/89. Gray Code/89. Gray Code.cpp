class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i=0;i<n;++i){
            for(int j=res.size()-1;j>=0;--j)
                res.push_back(res[j]|1<<i);
        }
        return res;
    }
};


//simple
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0;i<1<<n;++i){
            res.push_back(i^(i>>1));
        }
        return res;
    }
};