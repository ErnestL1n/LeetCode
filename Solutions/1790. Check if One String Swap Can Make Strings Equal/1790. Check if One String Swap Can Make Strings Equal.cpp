//wrong answer 
//test case s1="aa",s2="bb" it can't pass
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<char> m1,m2;
        for(int i=0;i<s1.size();++i){
            m1.push_back(s1[i]);
            m2.push_back(s2[i]);
        }
        int cnt=0;
        for(int i=0;i<s1.size();++i)
            if(m1[i]!=m2[i])
                ++cnt;      
        return cnt==2 || cnt==0;
    }
};