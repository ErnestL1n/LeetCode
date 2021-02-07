//Trick
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+(numBottles-1)/(numExchange-1);
    }
};



//straight forward
class Solution {
public:
    int numWaterBottles(int bts, int ex) {
        int res=bts;
        while(bts>=ex){
            int rem=bts%ex;
            bts/=ex;
            res+=bts;
            bts+=rem;
        }
        return res;
    }
};