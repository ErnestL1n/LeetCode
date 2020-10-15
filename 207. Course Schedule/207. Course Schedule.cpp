class Solution {
    vector<int> state; // -1 unvisited, 0 visiting, 1 visited
    bool dfs(vector<vector<int>> &G, int u) {
        if (state[u] != -1) return state[u];
        state[u] = 0;
        for (int v : G[u]) {
            if (!dfs(G, v)) return false;
        }
        return state[u] = 1;
    }
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        vector<vector<int>> G(N);
        state.assign(N, -1);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        for (int i = 0; i < N; ++i) {
            if (!dfs(G, i)) return false;
        }
        return true;
    }
};




class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        vector<vector<int>> G(N);
        vector<int> indegree(N);
        for (auto &e : E) {
            G[e[1]].push_back(e[0]);
            ++indegree[e[0]];
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ++cnt;
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return cnt == N;
    }
};











class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[][] graph=buildGraph(prerequisites,numCourses);
        int[] degree=countInDegree(graph);
        for(int i=0;i<prerequisites.length;++i){
            int j=0;
            for(;j<prerequisites.length;++j)
                if(degree[j]==0)
                    break;
            if(j==prerequisites.length)
                return false;
            degree[j]=-1;
            for(int d:graph[j])
                --degree[d];
        }
        return true;       
    }
    private int[][] buildGraph(int[][] prerequisites,int numCourses){
        int[][] g=new int[numCourses][];
        for(int i=0;i<prerequisites.length;++i)
            g[prerequisites[i][1]]=prerequisites[i][0];
        return g;
    }
    private int[] countInDegree(int[][] graph){
        int[] degree=new int[graph.length];
        for(int[] adj:graph)
            for(int d:adj)
                ++degree[d];
        return degree;
    }
}