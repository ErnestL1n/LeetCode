//BF=> TLE
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& q:queries){
            A[q[1]]+=q[0];
            int s=0;
            for(int a:A)
                if(a%2==0)
                    s+=a;
            res.push_back(s);
        }
        return res;
    }
};


//use accumulate
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries,vector<int> res={}) {
        int Evensum=accumulate(begin(A),end(A),0,[](int s,int a){return s+(a%2==0?a:0);});
        for(auto& q:queries){
            if(A[q[1]]%2==0)Evensum-=A[q[1]];
            A[q[1]]+=q[0];
            if(A[q[1]]%2==0)Evensum+=A[q[1]];
            res.push_back(Evensum);
        }
        return res;
    }
};


