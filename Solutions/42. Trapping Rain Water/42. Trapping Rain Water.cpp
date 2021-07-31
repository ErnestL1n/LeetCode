class Solution {
public:
    int trap(vector<int>& h) {
        int res=0,left=0,right=h.size()-1;
        int m_l=0,m_r=0;
        while(left<=right){
            if(h[left]<=h[right]){
                if(h[left]>=m_l)
                    m_l=h[left];
                else
                    res+=m_l-h[left];
                ++left;
            }else{
                if(h[right]>=m_r)
                    m_r=h[right];
                else 
                    res+=m_r-h[right];
                --right;
            }
        }
        return res;
    }
};