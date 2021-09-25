class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
      int n = grid.size(), m = grid[0].size();
      
      // {r, c, k_left, steps_count}
      queue<vector<int>> pending; 
      pending.push({0,0,k,0});
      
      // all 4 directions
      int dirs[4][4] = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
      };
      
      // visited array for (r,c,k)
      vector<vector<vector<int>>> visited(n, vector<vector<int>>(m,vector<int>(k+1,0)));
      visited[0][0][k] = 1;
      
      while(pending.size()){
        auto curr = pending.front(); 
        pending.pop();
        int r = curr[0], c = curr[1], k_left = curr[2], steps = curr[3];
        
        if(r == n-1 && c == m-1){
          return steps;   // we have reached the end with shortest path
        }
        
        for(auto &dir: dirs){
          int R = r+dir[0], C = c+dir[1];
          if(R>=0 && C>=0 && R<n && C<m && !visited[R][C][k_left]){ 
            // add them to queue if not visited
            visited[R][C][k_left] = 1;
            
            if(grid[R][C] == 1 && k_left > 0) 
              pending.push({R,C,k_left-1,steps+1});
            
            else if(grid[R][C] == 0)
              pending.push({R,C,k_left,steps+1});
          }
        }
      }
      
      // we never reached (n-1, m-1) point
      return -1;
    }
};