typedef struct trie{
    string word="";
    trie* ch[26]={};
}trie;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto root=buildtree(words);
        vector<string> res;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                dfs(board,i,j,root,res);
            }
        }
        return res;
    }
    trie* buildtree(vector<string>& words){
        trie* root=new trie();
        for(const auto& w:words){
            auto cur=root;
            for(int i=0;i<w.size();++i){
                if(cur->ch[w[i]-'a']==nullptr){
                    cur->ch[w[i]-'a']=new trie();
                }
                cur=cur->ch[w[i]-'a'];
            }
            cur->word=w;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board,int i,int j,trie* root,vector<string>& res){
        char c=board[i][j];
        if(c=='#' or root->ch[c-'a']==nullptr){
            return;
        }
        board[i][j]='#';
        root=root->ch[c-'a'];
        if(root->word.size()>0){
            res.push_back(root->word);
            root->word="";
        }
        board[i][j]='#';
        if(i>0){
            dfs(board,i-1,j,root,res);
        }
        if(j>0){
            dfs(board,i,j-1,root,res);
        }
        if(i<board.size()-1){
            dfs(board,i+1,j,root,res);
        }
        if(j<board[0].size()-1){
            dfs(board,i,j+1,root,res);
        }
        board[i][j]=c;
    }
};