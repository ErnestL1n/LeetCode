class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        vector<int> res(3);
        res[0]=1;
        res[1]=m1;
        res[2]=m2;
        while(m_ax(res[1],res[2])>=res[0]){
            int i=res[1]==m_ax(res[1],res[2])?1:2;
            res[i]-=res[0];
            ++res[0];
        }
        return res;
    }
    int m_ax(int i,int j){
        if(i>=j){
            return i;
        }
        return j;
    }
};


class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        int cnt=1;
        while(max(m1,m2)>=cnt){
            if(m1>=m2)
                m1-=cnt;
            else
                m2-=cnt;
            ++cnt;
        }
        return {cnt,m1,m2};
    }
};