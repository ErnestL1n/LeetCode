class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        sort(begin(p),end(p));
        int lo=0,hi=p.back()-p.front();
        while(lo<=hi){
            int dis=(lo+hi)/2;
            if(foo(p,dis,m))
                lo=dis+1;
            else{
                hi=dis-1;
            }
        }
        return hi;
    }
    
    bool foo(vector<int>&pos,int dis,int m){
        int used=0,begin=-1;
        for(int p:pos){
            if(begin<=p){
                ++used;
                begin=dis+p;
            }
        }
        return used>=m;
    }
};