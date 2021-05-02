/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

//priority_queue
class SeatManager {
public:
    //min heap
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

//set
class SeatManager {
public:
    set<int> s;
    SeatManager(int n) {
        for(int i=1;i<=n;++i)
            s.insert(i);
    }
    
    int reserve() {
        int r=*begin(s);
        s.erase(begin(s));
        return r;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};