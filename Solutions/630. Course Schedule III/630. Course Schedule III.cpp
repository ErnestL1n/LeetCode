class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        priority_queue<int> pq;
        int time=0;
        for(vector<int>& c:courses){
            time+=c[0];
            pq.push(c[0]);
            if(time>c[1]){
                time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};