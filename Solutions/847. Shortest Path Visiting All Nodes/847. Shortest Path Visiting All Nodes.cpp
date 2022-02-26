class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int kans=(1<<graph.size())-1;
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        for(int i=0;i<graph.size();++i){
            q.push({i,1<<i});
        }
        int steps=0;
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;++i){
                auto cur=q.front();q.pop();
                int n=cur.first;
                int state=cur.second;
                if(state==kans){
                    return steps;
                }
                int key=(n<<16)|state;
                if(visited.count(key)){
                    continue;
                }
                visited.insert(key);
                for(int next:graph[n]){
                    q.push({next,state|(1<<next)});
                }
            }
            ++steps;
        }
        return -1;
    }
};