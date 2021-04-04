class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size())
            swap(s1,s2);
        deque<string> q1,q2;
        s1.push_back(' ');
        s2.push_back(' ');
        for(int i=0;i<s1.size();++i){
            string tmp="";
            while(s1[i]!=' ')
                tmp+=s1[i++];
            q1.push_back(tmp);
        }
        for(int i=0;i<s2.size();++i){
            string tmp="";
            while(s2[i]!=' ')
                tmp+=s2[i++];
            q2.push_back(tmp);
        }
        // for(auto s:q1)
        //     cout << s <<"\n";
        // for(auto s:q2)
        //     cout << s <<"\n";
        while(q2.size()){
            if(q1.front()==q2.front()){
                q1.pop_front();
                q2.pop_front();
            }else if(q1.back()==q2.back()){
                q1.pop_back();
                q2.pop_back();
            }else
                return false;
        }
        return true;
    }
}; 