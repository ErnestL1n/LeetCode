class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& target) {
        int a,b,c;
        a=b=c=0;
        for(const auto& t:tri){
            if(t[0]<=target[0] and t[1]<=target[1] and t[2]<=target[2])
                a=max(a,t[0]),b=max(b,t[1]),c=max(c,t[2]);
            if(a==target[0] and b==target[1] and c==target[2])
                return true;
        }
        return false;
    }
};