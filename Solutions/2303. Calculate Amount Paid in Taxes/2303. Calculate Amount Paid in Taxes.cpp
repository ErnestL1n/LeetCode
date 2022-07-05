class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res=0,prev=0;
        for(int i=0;i<brackets.size();prev=brackets[i][0],++i){
            res+=max(0.0,(-prev+min(income,brackets[i][0]))*brackets[i][1]/100);
        }
        return res;
    }
};