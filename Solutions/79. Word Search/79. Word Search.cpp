class Solution {
public:
    inline static int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(foo(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool foo(vector<vector<char>>& board,string& word,int i,int j,int pos){
        if(i<0 or j<0 or i>=m or j>=n or board[i][j]!=word[pos]){
            return false;
        }
        if(pos==word.size()-1){
            return true;
        }
        auto cur=board[i][j];
        // tip avoid repetition
        board[i][j]='*';
        bool res=(foo(board,word,i+1,j,pos+1) or foo(board,word,i,j+1,pos+1)
          or foo(board,word,i-1,j,pos+1) or foo(board,word,i,j-1,pos+1));
        // tip unmark
        board[i][j]=cur;
        return res;
    }
};