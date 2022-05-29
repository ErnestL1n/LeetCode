class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> value(n);
        for(int i=0;i<n;++i){
            auto tmp=words[i];
            value[i]=0;
            for(int j=0;j<tmp.size();++j){
                value[i]|=1<<(tmp[j]-'a');
            }
        }
        int res=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if((value[i]&value[j])==0 and (words[i].size()*words[j].size()>res)){
                    res=words[i].size()*words[j].size();
                }
            }
        }
        return res;
    }
};