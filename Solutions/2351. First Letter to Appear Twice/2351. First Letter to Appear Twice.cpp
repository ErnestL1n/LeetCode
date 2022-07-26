class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> um;
        char res;
        for(auto& x:s){
            if(um.find(x)!=um.end()){
                res=x;
                break;
            }
            ++um[x];
        }
        return res;
    }
};