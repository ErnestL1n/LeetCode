class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int r=matrix.size(),c=matrix[0].size();
        vector<vector<int>> res(r+1,vector<int>(c+1,0));
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j){
                res[i+1][j+1]=matrix[i][j]^res[i+1][j]^res[i][j+1]^res[i][j];
                pq.push(res[i+1][j+1]);
                if(pq.size()>k)
                    pq.pop();
            }
        return pq.top();
    }
};