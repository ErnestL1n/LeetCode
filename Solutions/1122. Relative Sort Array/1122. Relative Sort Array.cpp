class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001),res;
        for(int i=0;i<arr1.size();++i)
            ++cnt[arr1[i]];
        for(int n:arr2){
            while(cnt[n]--)
                res.push_back(n);
        }
        for(int n=0;n<=1000;++n)
            while(cnt[n]-->0)
                res.push_back(n);
        return res;
    }
};