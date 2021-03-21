//std::prev
class Solution {
public:
    int secondHighest(string s) {
        set<int> si;
        for(auto ch:s)
            if(isdigit(ch))
                si.insert(ch-'0');
        return si.size()>1?*prev(end(si),2):-1;
    }
};

//std::next
class Solution {
public:
    int secondHighest(string s) {
        set<int> si;
        for(auto ch:s)
            if(isdigit(ch))
                si.insert(ch-'0');
        return si.size()>1?*next(rbegin(si)):-1;
    }
};



class Solution {
public:
    int secondHighest(string s) {
        int fst=-1,sec=-1;
        for(char ch:s){
            if(isdigit(ch)){
                int d=ch-'0';
                if(fst<d){
                    sec=fst;
                    fst=d;
                }else if(sec<d and d<fst){
                    sec=d;
                }
            }
        }
        return sec;
    }
};