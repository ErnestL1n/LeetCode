class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(const auto&c:t)
            ++m[c];
        int begin=0,end=0,cnt=t.size(),len=INT_MAX,head=0;
        while(end<s.size()){
            if(m[s[end++]]-->0)
                --cnt;
            while(cnt==0){
                if(end-begin<len){
                    len=end-begin;
                    head=begin;
                }
                if(m[s[begin++]]++==0)
                    ++cnt;
            }
        }
        return len==INT_MAX?"":s.substr(head,len);
    }
};