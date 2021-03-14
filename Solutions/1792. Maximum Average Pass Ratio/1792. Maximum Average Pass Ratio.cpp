typedef pair<double,array<int,2>> pdai2;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit=[](double pass,double total){
            return (pass+1)/(total+1)-pass/total;
        };
        double total=0;
        priority_queue<pdai2> pq;
        for(auto& c:classes){
            total+=(double)c[0]/c[1];
            pq.push({profit(c[0],c[1]),{c[0],c[1]}});
        }
        while(extraStudents--){
            auto [added_profit,c]=pq.top();pq.pop();
            total+=added_profit;
            pq.push({profit(c[0]+1,c[1]+1),{c[0]+1,c[1]+1}});
        }
        return total/classes.size();
    }
};


//make heap version
typedef pair<double,array<int,2>> pdai2;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit=[](double pass,double total){
            return (pass+1)/(total+1)-pass/total;
        };
        double total=0;
        vector<pdai2> heap;
        for(auto& c:classes){
            total+=(double)c[0]/c[1];
            heap.push_back({profit(c[0],c[1]),{c[0],c[1]}});
        }
        make_heap(begin(heap),end(heap));
        while(extraStudents--){
            pop_heap(begin(heap),end(heap));
            auto [added_profit,c]=heap.back();heap.pop_back();
            total+=added_profit;
            heap.push_back({profit(c[0]+1,c[1]+1),{c[0]+1,c[1]+1}});
            push_heap(begin(heap),end(heap));
        }
        return total/classes.size();
    }
};