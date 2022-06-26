class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(),lsum=0;
        for(int i=0;i<k;++i){
            lsum+=cardPoints[i];
        }
        int mx=lsum;
        for(int rsum=0,i=0;i<k;++i){
            rsum+=cardPoints[n-i-1];
            lsum-=cardPoints[k-1-i];
            mx=max(mx,lsum+rsum);
        }
        return mx;
    }
};