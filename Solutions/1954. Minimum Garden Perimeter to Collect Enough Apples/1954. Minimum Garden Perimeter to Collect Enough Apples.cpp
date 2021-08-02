//Time O(logX^(1/3)), where X is the range of input
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long lo=1,hi=1e5; //since 1 <= neededApples <= 10^15
        while(lo<hi){
            int m=(lo+hi)/2;
            if(4*(pow(m,3))+6*pow(m,2)+2*m>=neededApples)
                hi=m;
            else
                lo=m+1;
        }
        return 8*lo;
    }
};

