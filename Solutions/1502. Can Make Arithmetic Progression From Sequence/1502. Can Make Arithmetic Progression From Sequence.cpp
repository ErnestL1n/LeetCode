class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> seen;
        int n=arr.size(),m_in=INT_MAX,m_ax=INT_MIN;
        for(int a:arr){
            m_in=min(a,m_in);
            m_ax=max(a,m_ax);
            seen.insert(a);
        }
        int diff=m_ax-m_in;
        if(diff%(n-1)!=0)
            return false;
        diff/=(n-1);
        while(--n > 0){
            if(seen.find(m_in)==seen.end())
                return false;
            m_in+=diff;
        }
        return true;
    }
};


class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=1;arr.size()-1;++i)
            if(arr[i-1]-arr[i]!=arr[i]-arr[i+1])
                return false;
        return true;
    }
};