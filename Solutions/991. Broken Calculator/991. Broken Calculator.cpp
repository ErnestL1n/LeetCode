class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res=0;
        while(startValue<target){
            target=target%2>0?target+1:target/2;
            ++res;
        }
        return res+startValue-target;
    }
};