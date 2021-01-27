class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int res=0;
        vector<int> row(g.size()),col(g[0].size());
        for(int i=0;i<g.size();++i)
            for(int j=0;j<g[0].size();++j)
                if(g[i][j])
                    ++row[i],++col[j];
        for(int i=0;i<g.size();++i)
            for(int j=0;j<g[0].size();++j)
                if(g[i][j]&&(row[i]>1||col[j]>1))
                    ++res;
        return res;
    }
};