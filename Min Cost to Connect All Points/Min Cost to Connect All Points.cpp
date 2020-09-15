int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
int minCostConnectPoints(vector<vector<int>>& ps) {
    int n = ps.size(), res = 0;
    vector<int> ds(n, -1);
    vector<array<int, 3>> arr;
    for (auto i = 0; i < n; ++i)
        for (auto j = i + 1; j < n; ++j) {
            arr.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
        }
    make_heap(begin(arr), end(arr), greater<array<int, 3>>());
    while (!arr.empty()) {
        pop_heap(begin(arr), end(arr), greater<array<int, 3>>());
        auto [dist, i, j] = arr.back();
        arr.pop_back();
        i = find(ds, i), j = find(ds, j);
        if (i != j) {
            res += dist;
            ds[i] += ds[j];
            ds[j] = i;
            if (ds[i] == -n)
                break;
        }
    }
    return res;
}





/*
class Union{
    int components;
    vector<int> component;
public:
    Union(int n){
        components=n;
        for(int i=0;i<=n;++i)
            component.push_back(i);
    }
    int Find(int a){
        if(component[a]!=a)
            component[a]=Find(component[a]);
        return component[a];
    }
    bool Unite(int a,int b){
        if(Find(a)==Find(b))
            return false;
        component[Find(a)]=b;
        --components;
        return true;
    }
    bool United(){
        return components==1;
    }
    
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size=points.size();
        vector<array<int,3>> edges;
        for(int i=0;i<size-1;++i)
            for(int j=i+1;j<size;++j){
                int dist = abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1]); // Manhattan distance.
                edges.push_back({dist, i, j}); // Add the edge.
            }
        make_heap(edges.begin(), edges.end(), greater<>());  // For heap sort.
        Union uf(size);   // Very important to have this data structure ready.
        int cost = 0;      // Stores the cost.
        while(!edges.empty() && !uf.United()) { // Until the forest is not a single component.
            pop_heap(edges.begin(), edges.end(), greater<>()); 
            auto edge = edges.back(); // Minimum cost edge.
            int p1 = edge[1];  // Point 1
            int p2 = edge[2];  // Point 2
            if (uf.Unite(p1, p2)) {  // Merge two components.
                cost += edge[0];  // Add the cost if they were not already merged.
            }
            edges.pop_back();  // Remove the lowest cost edge.
        }
        return cost;   // Yay, solved.
    }
};
*/