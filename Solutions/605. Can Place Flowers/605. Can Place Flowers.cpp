class Solution {
public:
    bool canPlaceFlowers(vector<int>& fw, int n) {
        int cnt=0;
        for(int i=0;i<fw.size() and cnt<n;++i){
            if(fw[i]==0){
                int prev=i==0?0:fw[i-1];
                int next=i==fw.size()-1?0:fw[i+1];
                if(prev==0 and next==0){
                    fw[i]=1;
                    ++cnt;
                }
            }
        }
        return cnt==n;
    }
};