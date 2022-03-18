class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26]={};
        bool visited[26]={};
        for(auto& c:s){
            ++cnt[c-'a'];
        }
        string res;
        for(auto& c:s){
            int idx=c-'a';
            --cnt[idx];
            if(visited[idx]){
                continue;
            }
            while(res.size()>0 and c<res.back() and cnt[res.back()-'a']!=0){
                visited[res.back()-'a']=false;
                res.pop_back();
            }
            res.push_back(c);
            visited[idx]=true;
        }
        return res;
    }
};