// simplify version
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res=0;
        unordered_map<int,int> m;
        for(auto a:A)
            for(auto b:B)
                ++m[a+b];
        for(auto c:C)
            for(auto d:D)
                res+=m[-c-d];
        return res;
    }
};

// find version
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res=0;
        unordered_map<int,int> m;
        for(auto a:A)
            for(auto b:B)
                ++m[a+b];
        for(auto c:C)
            for(auto d:D){
                if(m.find(0-c-d)!=m.end())
                    res+=m[0-c-d];
            }
        return res;
    }
};