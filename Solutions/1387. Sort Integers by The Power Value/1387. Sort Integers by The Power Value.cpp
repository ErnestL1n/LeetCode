typedef pair<int,int> pr;
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        for(int i=lo;i<=hi;++i){
            int cnt=0;
            auto x=i;
            while(x!=1){
                if(x%2)
                    x=x*3+1;
                else
                    x/=2;
                ++cnt;
            }
            pq.push(make_pair(cnt,i));
        }
        while(--k)
            pq.pop();
        return pq.top().second;
    }
};