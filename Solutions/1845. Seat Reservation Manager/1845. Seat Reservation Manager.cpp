class SeatManager {
public:
    //max heap
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        for(int i=1;i<=n;++i)
            pq.push(i);
    }
    
    int reserve() {
        int r=pq.top();
        pq.pop();
        return r;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */