class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int res=1;
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;++i){
                auto cur=q.front();q.pop();
                if(cur==endWord){
                    return res;
                }
                for(int j=0;j<cur.size();++j){
                    auto c=cur[j];
                    for(int k=0;k<26;++k){
                        cur[j]=k+'a';
                        if(us.find(cur)!=us.end()){
                            us.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[j]=c;
                }
            }
            ++res;
        }
        return 0;
    }
};