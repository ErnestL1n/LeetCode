class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string a,string b){
            return a.size()<b.size();
        });
        unordered_map<string,int> dp;
        int res=0;
        for(string w:words){
            for(int i=0;i<w.size();++i){
                string pre=w.substr(0,i)+w.substr(i+1);
                dp[w]=max(dp[w],dp.find(pre)==dp.end()?1:dp[pre]+1);
            }
            res=max(res,dp[w]);
        }
        return res;
    }
};