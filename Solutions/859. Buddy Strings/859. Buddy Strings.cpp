class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.size()!=b.size())
            return false;
        if(a==b and set<char>(a.begin(),a.end()).size()<a.size())
            return true;
        vector<array<char,2>> m;
        for(int i=0;i<a.size()&&m.size()<3;++i)
            if(a[i]!=b[i])
                m.push_back({m.size()?a[i]:b[i],m.size()?b[i]:a[i]});
        return m.size()==2 and m[0]==m[1];
    }
};