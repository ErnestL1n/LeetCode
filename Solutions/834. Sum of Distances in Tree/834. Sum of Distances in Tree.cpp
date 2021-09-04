class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> res,cnt;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.assign(n,0);
        cnt.assign(n,1);
        for(const auto& e:edges){
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        foo(0,-1);
        bar(0,-1);
        return res;
    }
    void foo(int root,int pre){
        for(const auto& t:tree[root]){
            if(t==pre)
                continue;
            foo(t,root);
            cnt[root]+=cnt[t];
            res[root]+=res[t]+cnt[t];
        }
    }
    void bar(int root,int pre){
        for (const auto& t:tree[root]) {
            if(t==pre) 
                continue;
            res[t]=res[root]-cnt[t]+cnt.size()-cnt[t];
            bar(t,root);
        }
    }
};