class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int res=0,k;
        int cnt[]={0,0};
        for(auto s:students){
            ++cnt[s];
        }
        for(k=0;k<sandwiches.size()&&cnt[sandwiches[k]]>0;++k)
            --cnt[sandwiches[k]];
        return students.size()-k;
    }
};