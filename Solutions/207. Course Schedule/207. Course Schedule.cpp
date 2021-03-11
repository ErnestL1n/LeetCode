class Solution {
public:
    vector<int> state; // -1 unvisited, 0 visiting, 1 visited
    bool dfs(vector<vector<int>>& G,int u){
        if(state[u]!=-1)
            return state[u];
        state[u]=0;
        for(int v:G[u])
            if(dfs(G,v)==0)
                return false;
        return state[u]=1;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> G(n);
        state.assign(n,-1);
        for(auto& p:pre)
            G[p[1]].push_back(p[0]);
        for(int i=0;i<n;++i)
            if(!dfs(G,i))
                return false;
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










//BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<pair<int,int>> prerequisites;
        for(int i=0;i<p.size();++i)
            prerequisites.push_back(make_pair(p[i][0],p[i][1]));
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};





//DFS
typedef pair<int,int> pr;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pr> p;
        for(int i=0;i<prerequisites.size();++i)
            p.push_back(make_pair(prerequisites[i][0],prerequisites[i][1]));
        graph g=buildGraph(p,numCourses);
        vector<bool> todo(numCourses,false),done(numCourses,false);
        for(int i=0;i<numCourses;++i){
            if(!done[i]&&!acyclic(g,todo,done,i))
                return false;
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    graph buildGraph(vector<pr>& prerequisites,int numCourses){
        graph g(numCourses);
        for(auto&p:prerequisites)
            g[p.second].push_back(p.first);
        return g;
    }
    bool acyclic(graph& g,vector<bool>& todo,vector<bool>& done,int node){
        if(todo[node])
            return false;
        if(done[node])
            return true;
        todo[node]=done[node]=true;
        for(int v:g[node])
            if(!acyclic(g,todo,done,v))
                return false;
        todo[node]=false;
        return true;
    }
};