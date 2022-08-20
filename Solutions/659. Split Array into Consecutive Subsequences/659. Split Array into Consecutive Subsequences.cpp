class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel>=target){
            return 0;
        }
        priority_queue<int> q;
        int i=0,n=stations.size(),stops=0,maxD=startFuel;
        while (maxD<target){
            while(i<n and stations[i][0]<=maxD){
                q.push(stations[i++][1]);
            }
            if(q.size()==0){
                return -1;
            }
            maxD+=q.top();q.pop();
            ++stops;
        }
        return stops;
    }
};