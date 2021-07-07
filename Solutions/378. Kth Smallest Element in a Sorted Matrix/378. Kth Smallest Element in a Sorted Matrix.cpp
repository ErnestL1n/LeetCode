//priority queue
typedef pair<int,pair<int,int>> pr;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {   
        int n=mat.size();
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        for(int i=0;i<n and i<k;++i)
            pq.push({mat[i][0],{i,0}});
        int cnt=0,res=0;
        while(pq.size()){
            auto cur=pq.top();pq.pop();
            res=cur.first;
            if(++cnt==k)
                break;
            ++cur.second.second;
            if(n>cur.second.second){
                cur.first=mat[cur.second.first][cur.second.second];
                pq.push(cur);
            }
        }
        return res;
    }
};


//binary search