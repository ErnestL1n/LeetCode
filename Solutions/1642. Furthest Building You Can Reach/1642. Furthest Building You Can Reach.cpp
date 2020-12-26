class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<h.size()-1;++i){
            int dis=h[i+1]-h[i];
            if(dis>0)
                pq.push(dis);
            if(pq.size()>ladders){
                bricks-=pq.top();
                pq.pop();
            }
            if(bricks<0)
                return i;
        }
        return h.size()-1;
    }
};