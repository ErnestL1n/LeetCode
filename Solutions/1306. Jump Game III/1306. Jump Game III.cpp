class Solution {
public:
    bool canReach(vector<int>& arr, int st) {
        if(st<0 or st>=arr.size() or arr[st]<0){
            return false;
        }
        if(arr[st]==0){
            return true;
        }
        arr[st]=-arr[st];
        return canReach(arr,st+arr[st]) or canReach(arr,st-arr[st]);
    }
};