class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_idx(26);
        for(int i=0;i<s.size();++i){
            last_idx[s[i]-'a']=i;
        }
        int ed=0,st=0;
        vector<int> res;
        for(int i=0;i<s.size();++i){
            ed=max(ed,last_idx[s[i]-'a']);
            if(ed==i){
                res.push_back(ed-st+1);
                st=ed+1;
            }
        }
        return res;
    }
};