class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[&](vector<int> p1,vector<int> p2){
            return p1[0]>p2[0] or (p1[0]==p2[0] and p1[1]<p2[1]);
        });
        vector<vector<int>> res;
        for(auto& p:people){
            res.insert(res.begin()+p[1],p);
        }
        return res;
    }
};class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int cnt=0;
        while(i<j){
            cnt+=nums[j--]-nums[i++];
        }
        return cnt;
    }
};