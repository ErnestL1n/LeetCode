class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(auto log:logs){
            if(log=="./")continue;
            else if(log=="../"){
                --depth;
                if(depth<0)depth=0;
            }
            else
                ++depth;
        }
        return depth;
    }
};