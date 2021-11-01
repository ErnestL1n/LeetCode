class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        // mark board region with border 
        function<void(int,int)> foo=[&](int i,int j){
            if(i<0 or j<0 or i>=m or j>=n or board[i][j]!='O'){
                return;
            }
            board[i][j]='Q';
            foo(i-1,j),foo(i,j-1),foo(i+1,j),foo(i,j+1);
        };
        
        // start from border
        for(int i=0;i<m;++i){
            foo(i,0),foo(i,n-1);
        }
        for(int j=0;j<n;++j){
            foo(0,j),foo(m-1,j);
        }
        // change pattern
        unordered_map<char,char> v{{'Q','O'},{'O','X'}};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='X'){
                    continue;
                }else{
                    board[i][j]=v[board[i][j]];
                }
            }
        }
    }
};