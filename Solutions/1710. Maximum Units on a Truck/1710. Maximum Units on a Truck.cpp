class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes),end(boxTypes),[](vector<int>& first,vector<int>& second){return first[1]>second[1];});
        int res=0;
        for(auto bt:boxTypes){
            int x=min(bt[0],truckSize);
            res+=x*bt[1];
            truckSize-=x;
            if(!truckSize)
                break;
        }
        return res;
    }
};