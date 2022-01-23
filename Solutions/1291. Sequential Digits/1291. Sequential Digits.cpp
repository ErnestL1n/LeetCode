class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1;i<=9;++i){
            q.push(i);
        }
        vector<int> res;
        while(q.size()){
            int f=q.front();
            q.pop();
            if(f<=high and f>=low){
                res.push_back(f);
            }
            if(f>high){
                break;
            }
            int num=f%10;
            if(num<=8){
                q.push({f*10+(num+1)});
            }
        }
        return res;
    }
};