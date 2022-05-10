class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        combination(res,tmp,k,1,n);
        return res;
    }
    void combination(vector<vector<int>>& res,vector<int>& tmp,int& k,int st,int n){
        if(tmp.size()==k and n==0){
            res.push_back(tmp);
            return;
        }
        for(int i=st;i<=9;++i){
            tmp.push_back(i);
            combination(res,tmp,k,i+1,n-i);
            tmp.pop_back();
        }
    }
};