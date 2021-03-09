class Solution {
public:
    double average(vector<int>& salary) {
        sort(begin(salary),end(salary));
        return (double)accumulate(begin(salary)+1,end(salary)-1,0)/(salary.size()-2);
    }
};