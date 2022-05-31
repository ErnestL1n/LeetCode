class Solution {
public:
    bool hasAllCodes(string s, int k) {
        deque<char> q;
        unordered_set<string> us;
        for(auto& c:s){
            q.push_back(c);
            if(q.size()==k){
                us.insert({q.begin(),q.end()});
                q.pop_front();
            }
        }
        return us.size()==1<<k;
    }
};