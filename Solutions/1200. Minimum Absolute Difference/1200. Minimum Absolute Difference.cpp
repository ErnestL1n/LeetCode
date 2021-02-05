class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=0;i<arr.size()-1;++i){
            int diff=arr[i+1]-arr[i];
            if(diff<mini){
                mini=diff;
                res.clear();
                res.push_back({arr[i],arr[i+1]});
            }
            else if(diff==mini)
                res.push_back({arr[i],arr[i+1]});
        }
        return res;
    }
};