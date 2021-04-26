class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level=0;
        while(1<<level<=label)
            ++level;
        cout << level << "\n";
        vector<int> res(level);
        while(label!=0){
            res[level-1]=label;
            label=((1<<level)-1+(1<<(level-1))-label)/2;
            --level;
        }
        return res;
    }
};