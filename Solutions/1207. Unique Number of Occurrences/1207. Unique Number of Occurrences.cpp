class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int a:arr)
            ++m[a];
        for(auto& p:m)
            s.insert(p.second);
        // cout <<m.size() << "、" <<s.size() <<"\n";
        // arr=[1,2,2,1,1,3]  =>  3、3 
        // arr=[1,2]  =>  2、1
        return s.size()==m.size();
    }
};


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int a:arr)
            ++m[a];
        for(auto& p:m)
            if(!s.insert(p.second).second)
                return false;
        return true;
    }
};