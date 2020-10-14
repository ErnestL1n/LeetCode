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