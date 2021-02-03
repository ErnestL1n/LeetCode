typedef pair<double,pair<int,int>> pr;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        for(int i=0;i<arr.size();++i)
            for(int j=i+1;j<arr.size();++j)
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            
        while(--k)
            pq.pop();
        return vector<int>{pq.top().second.first,pq.top().second.second};
    }
};
