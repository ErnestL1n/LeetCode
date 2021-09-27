class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int res=0;
        set<string> s;
        for(const auto& e:emails){
            bool flag=false;
            int i;
            string tmp;
            for(i=0;i<e.size() and e[i]!='@';++i){
                if(e[i]=='.' and !flag)
                    continue;
                if(e[i]=='+')
                    flag=true;
                if(!flag)
                    tmp+=e[i];
            }
            tmp+=e.substr(i);
            s.insert(tmp);
        }
        return s.size();
    }
};