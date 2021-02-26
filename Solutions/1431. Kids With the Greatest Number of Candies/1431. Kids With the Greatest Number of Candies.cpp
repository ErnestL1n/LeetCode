class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extrac) {
        int m_c=INT_MIN;
        vector<bool> res;
        for(int c:candies)
            if(m_c<c)
                m_c=c;
        for(int c:candies){
            if(c+extrac<m_c)
                res.push_back(false);
            else
                res.push_back(true);
        }
        return res;
    }
};