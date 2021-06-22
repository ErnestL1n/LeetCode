class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        vector<vector<char>> res(n,vector<char>(m,'.'));
        for(int i=0;i<m;++i)
            for(int jfont=n-1,jback=n-1;jfont>=0;--jfont){
                if(box[i][jfont]!='.'){
                    jback=box[i][jfont]=='*'?jfont:jback;
                    res[jback--][m-1-i]=box[i][jfont];
                }
            }
        return res;
    }
};