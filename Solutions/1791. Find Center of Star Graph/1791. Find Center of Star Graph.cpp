class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //constraints:edges.length == n - 1
        int n=edges.size()+1;
        unordered_map<int,int> m;
        for(auto& e:edges)
            ++m[e[0]],++m[e[1]];
        for(auto [k,v]:m)
            if(v==n-1)  //or v>1 also can pass
                return k;
        assert(false);
    }
};

//1-liner
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]?edges[0][0]:edges[0][1];
    }
};