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


//count with sort
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        short m[2001]={};
        for(auto n:arr)
            ++m[n+1000];
        sort(begin(m),end(m));
        for(int i=1;i<=2000;++i)
            if(m[i]&&m[i]==m[i-1])
                return false;
        return true;
    }
};

//count without sort since 1<=arr.size()<=1000
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        short m[2001]={},s[1001]={};
        for(int n:arr)
            ++m[n+1000];
        for(int i=0;i<2001;++i)
            if(m[i]&&++s[m[i]]>1)
                return false;
        return true;
    }
};