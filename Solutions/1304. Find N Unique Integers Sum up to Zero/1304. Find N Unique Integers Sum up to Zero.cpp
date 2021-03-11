class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for(int i=0;i<n;++i)
            res.push_back(i*2-n+1);
        return res;
    }
};