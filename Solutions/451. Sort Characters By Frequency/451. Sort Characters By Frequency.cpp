//bucket sort
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(const auto& c:s)
            ++m[c];
        //create bucket number from "0" to "s.size()+1"
        vector<vector<char>> bucket(s.size()+1);
        for(const auto& [k,v]:m)
            bucket[v].push_back(k);
        string res="";
        //push_back from the largest size one
        for(int i=bucket.size()-1;i>=0;--i){
            for(char c:bucket[i])
                for(int j=0;j<i;++j)
                    res+=c;
        }
        return res;
    }
};

//using priority queue
class foo{
public:
    //always seem priority queue a reverse order
    bool operator()(pair<char,int>& a,pair<char,int>& b){
        return a.second<b.second;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(const auto& c:s)
            ++m[c];
        priority_queue<pair<char,int>,vector<pair<char,int>>,foo> pq;
        for(const auto& [k,v]:m)
            pq.push({k,v});
        string res="";
        while(pq.size()){
            auto cur=pq.top();pq.pop();
            while(cur.second--)
                res+=cur.first;
        }
        return res;
    }
};