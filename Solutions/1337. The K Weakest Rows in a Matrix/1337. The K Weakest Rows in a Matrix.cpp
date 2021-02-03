class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> s;
        for(int i=0;i<mat.size();++i){
            auto p=accumulate(begin(mat[i]),end(mat[i]),0);
            s.insert({p,i});
        }
        vector<int> res;
        for(auto it=begin(s);k>0;++it,--k)
            res.push_back(it->second);
        return res;
    }
};



// priority queue + binary search
typedef pair<int,int> pr;
class Solution {
public:
    struct cmp{
        bool operator()(const pr& a,const pr& b){
            return a.first!=b.first?a.first>b.first:a.second>b.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pr,vector<pr>,cmp> pq;
        vector<int> res;
        for(int i=0;i<mat.size();++i){
            pq.push({numOnes(mat[i]),i});
        }
        while(k--){
            res.push_back(pq.top().second),pq.pop();
        }
        return res;
    }
    int numOnes(vector<int>& row){
        int l=0,r=row.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(row[m]==1)
                l=m+1;
            else
                r=m-1;
        }
        return l;
    }
};
