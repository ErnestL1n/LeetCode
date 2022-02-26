class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int kAns = (1 << (graph.size())) - 1;    
    queue<pair<int, int>> q;
    unordered_set<int> visited; // (cur_node << 16) | state
    for (int i = 0; i < graph.size(); ++i)
      q.push({i, 1 << i});
    int steps = 0;
    while (!q.empty()) {
      int s = q.size();      
      while (s--) {
        auto p = q.front(); 
        q.pop();
        int n = p.first;
        int state = p.second;
        if (state == kAns) return steps;
        int key = (n << 16) | state;
        if (visited.count(key)) continue;
        visited.insert(key);
        for (int next : graph[n])
          q.push({next, state | (1 << next)});
      }
      ++steps;
    }
    return -1;
  }
};