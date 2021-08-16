class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26]={};
        for(const auto& c:s)
            ++cnt[c-'a'];
        int o=-1;
        for(int i=0;i<26;++i){
            if(cnt[i]==0)
                continue;
            o=cnt[i];
            break;
        }
        for(int i=0;i<26;++i)
            if(cnt[i]!=0 and cnt[i]!=o)
                return false;
        return true;
    }
};

//clean with STL
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26]={},m_cnt=0;
        for(const auto& c:s)
            m_cnt=max(m_cnt,++cnt[c-'a']);
        return all_of(begin(cnt),end(cnt),[&m_cnt](const int& t){return t==0 or t==m_cnt;});
    }
};