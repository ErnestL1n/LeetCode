class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    char n=board[i][j];
                    string a=string(1,n)+" in row "+to_string(i);
                    string b=string(1,n)+" in col "+to_string(j);
                    string c=string(1,n)+" in block "+to_string(i/3)+to_string(j/3);
                    if(s.find(a)!=s.end())
                        return false;
                    s.insert(a);
                    if(s.find(b)!=s.end())
                        return false;
                    s.insert(b);
                    if(s.find(c)!=s.end())
                        return false;
                    s.insert(c);
                }
            }
        }
        return true;
    }
};