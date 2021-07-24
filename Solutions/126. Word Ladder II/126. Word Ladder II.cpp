class Solution {
public:
    unordered_set<string> wordList;
    vector<vector<string>> res;
    unordered_set<string> visited;          
    int level = 1;
    int minLevel = INT_MAX;
    vector<vector<string>> findLadders(string beginWord, string endWord,vector<string> &words ) {
        for(auto word: words)
            wordList.insert(word);
        queue<vector<string>> q;
        q.push({beginWord});
        while (!q.empty()) 
        {
            vector<string> path = q.front(); q.pop();        
            if (path.size() > level)
            {
                for (string w : visited) 
                    wordList.erase(w);

                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            
            
            string lastWord = path.back();
            
            addNeighboursToQ(lastWord,path,q,endWord);
        }
        
        return res;
    }
    
    void addNeighboursToQ(string curr,vector<string> path,queue<vector<string>> &q,const string &endWord)
    {
            for(int i=0;i<curr.size();i++) 
            {
                char originalChar = curr[i];

                for(int j=0;j<26;j++)
                {
                    curr[i] = j + 'a';
                    
                    if(wordList.find(curr)!=wordList.end())
                    {
                        vector<string> newpath = path;
                        newpath.push_back(curr);                      
                        visited.insert(curr);

                        if (curr == endWord) {
                            minLevel = level;
                            res.push_back(newpath);
                        }
                        else
                            q.push(newpath);             
                    }
                }             
                curr[i] = originalChar;
            }
    }
};