class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res=0;
        unordered_set<char> st;
        for(auto j:jewels)
            st.insert(j);
        for(auto s:stones)
            res+=st.count(s);
        return res;
    }
};