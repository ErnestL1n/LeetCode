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


//straightforward answer
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<char> m1,m2;
        for(int i=0;i<s1.size();++i){
            if(s1[i]!=s2[i]){
                m1.push_back(s1[i]);
                m2.push_back(s2[i]);
            }
        }
        if(m1.size()==0)
            return true;
        if(m1.size()==2){
            return m1[0]==m2[1]&&m1[1]==m2[0];
        }
        return false;
    }
};



//clean solution
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<array<char,2>> mis;
        for(int i=0;i<s1.size()&&mis.size()<3;++i)
            if(s1[i]!=s2[i])
                mis.push_back({mis.size()?s1[i]:s2[i],mis.size()?s2[i]:s1[i]});
         return mis.size()==0 || mis.size()==2&&mis[0]==mis[1];
    }
};