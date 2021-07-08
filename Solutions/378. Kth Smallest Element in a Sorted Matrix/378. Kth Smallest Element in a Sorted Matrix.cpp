//priority queue
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        //put elements of row 0 into pq
        for(int j=0;j<n;++j)
            pq.push({mat[0][j],0,j});
        //k-1 times
        while(--k){
            auto cur=pq.top();pq.pop();
            //in the last row
            if(cur[1]==m-1)
                continue;
            pq.push({mat[cur[1]+1][cur[2]],cur[1]+1,cur[2]});
        }
        return pq.top()[0];
    }
};


//binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        int lo=mat[0][0],hi=mat[m-1][n-1]+1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int cnt=0,j=n-1;
            for(int i=0;i<m;++i){
                while(j>=0 and mat[i][j]>mid)
                    --j;
                cnt+=(j+1);
            }
            if(cnt<k)
                lo=mid+1;
            else
                hi=mid;
        }
        return lo;
    }
};