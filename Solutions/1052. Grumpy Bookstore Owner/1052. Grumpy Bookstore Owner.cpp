class Solution {
public:
    int maxSatisfied(vector<int>& cs, vector<int>& grum, int X) {
        int satisfied=0,add_satisfied=0,m_add_satisfied=0;
        for(int i=0;i<cs.size();++i){
            satisfied+=grum[i]?0:cs[i];
            add_satisfied+=grum[i]?cs[i]:0;
            if(i>=X)
                add_satisfied-=grum[i-X]?cs[i-X]:0;
            m_add_satisfied=max(m_add_satisfied,add_satisfied);
        }
        return satisfied+m_add_satisfied;
    }
};