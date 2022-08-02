class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int seq=0,cnt=0,dice[100001]={};
        for(int& r:rolls){
            if(dice[r]==seq){
                dice[r]=seq+1;
                if(++cnt%k==0){
                    ++seq;
                }
            }
        }
        return seq+1;
    }
};