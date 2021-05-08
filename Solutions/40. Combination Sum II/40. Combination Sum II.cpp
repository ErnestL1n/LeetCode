typedef vector<vector<int>> VVI;
typedef vector<int> VI;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        VVI res;
        VI path;
        sort(begin(candidates),end(candidates));
        foo(candidates,target,res,path,0);
        return res;
    }
    void foo(VI& c,int t,VVI& res,VI& path,int begin){
        if(t<=0){
            if(t==0){
                res.push_back(path);
                return;
            }
            return;
        }
        for(int i=begin;i<c.size();++i){
            if(i>begin and c[i]==c[i-1])
                continue;
            path.push_back(c[i]);
            foo(c,t-c[i],res,path,i+1);
            path.pop_back();
        }
    }
};