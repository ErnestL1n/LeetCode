class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> dict={
            {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'},
            {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'},
            {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'}};
        vector<string> res;
        for(auto word:words){
            vector<bool> check(3,true);
            for(char c:word){
                for(int i=0;i<3;++i){
                    if(check[i]&&dict[i].find(c)==dict[i].end())
                        check[i]=false;
                }
            }
            if(check[0]||check[1]||check[2])
                res.push_back(word);
        }
        return res;
    }
};