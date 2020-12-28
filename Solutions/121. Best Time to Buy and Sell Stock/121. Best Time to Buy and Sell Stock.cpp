class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res=0,minv=INT_MAX;
        for(int i=0;i<p.size();++i){
            if(minv>p[i])
                minv=p[i];
            else
                res=max(res,p[i]-minv);     
        }
        return res;
    }
};


//dp
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res=0,n=p.size();
        vector<int> record(n,0);
        for(int i=1;i<p.size();++i){
            record[i]=max(0,record[i-1]+p[i]-p[i-1]);
            res=max(record[i],res);
        }
        return res;
    }
};;