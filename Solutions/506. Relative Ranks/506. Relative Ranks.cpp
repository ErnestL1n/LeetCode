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