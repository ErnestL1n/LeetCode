class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> m;
        for(auto& w:words){
            int mask=0;
            for(int i=0;i<w.size();++i){
                mask|=1<<(w[i]-'a');
            }
            ++m[mask];
        }
        vector<int> res;
        for(auto& p:puzzles){
            int mask=0;
            for(int i=0;i<p.size();++i){
                mask|=1<<p[i]-'a';
            }
            int c=0;
            int sub=mask;
            int first=1<<(p[0]-'a');
            while(true){
                if((sub&first)==first and m[sub]){
                    c+=m[sub];
                }
                if(sub==0)
                    break;
                sub=(sub-1)&mask;
            }
            res.push_back(c);
        }
        return res;
    }
};