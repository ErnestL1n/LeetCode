class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int start=1,curr=0;
        vector<int> res;
        for(int i=0,j=2;i<encoded.size();++i,++j){
            curr^=encoded[i];
            start^=j^curr;
        }
        res.push_back(start);
        for(int i=0;i<encoded.size();++i)
            res.push_back(res.back()^encoded[i]);
        return res;
    }
};