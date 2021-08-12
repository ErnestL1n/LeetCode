class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res;
        unordered_map<int,string> m;
        int cnt=0;
        priority_queue<int> pq(score.begin(),score.end());
        while(pq.size()){
            ++cnt;
            auto cur=pq.top();pq.pop();
            if(cnt==1){
                m[cur]="Gold Medal";
            }else if(cnt==2){
                m[cur]="Silver Medal";
            }else if(cnt==3){
                m[cur]="Bronze Medal";
            }else{
                m[cur]=to_string(cnt);
            }
        }
        for(const int& s:score)
            res.push_back(m[s]);
        return res;
    }
};

// sort and not using map&priority_queue
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> idx(score.size());
        for(int i=0;i<score.size();++i){
            idx[i]=i;
        }
        sort(idx.begin(),idx.end(),[&score](int i,int j){return score[i]>score[j];});
        vector<string> res(score.size());
        for(int i=0;i<score.size();++i){
            if(i==0)
                res[idx[i]]="Gold Medal";
            else if(i==1)
                res[idx[i]]="Silver Medal";
            else if(i==2)
                res[idx[i]]="Bronze Medal";
            else
                res[idx[i]]=to_string(i+1);
        }
        return res;
    }
};