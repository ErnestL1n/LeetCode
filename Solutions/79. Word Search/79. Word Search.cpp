class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(foo(i,j,0,word,board))
                    return true;
            }
        }
        return false;
    }
    bool foo(int x,int y,int start,string& word,vector<vector<char>>& board){
        if(x<0 or y<0 or x>=m or y>=n)
            return false;
        if(word[start]!=board[x][y])
            return false;
        if(start==word.size()-1)
            return true;
        auto cur=board[x][y];
        board[x][y]='*';
        bool res=foo(x-1,y,start+1,word,board) or 
            foo(x,y-1,start+1,word,board) or
            foo(x+1,y,start+1,word,board) or
            foo(x,y+1,start+1,word,board);
        board[x][y]=cur;
        return res;
    }
};