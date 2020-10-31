class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size());
        for(int i=0;i<l.size();++i){
            vector<int> temp(begin(nums)+l[i],begin(nums)+r[i]+1);
            sort(begin(temp),end(temp));
            res[i]=true;
            for(int j=1;j<temp.size();++j){
                if(temp[j]-temp[j-1]!=temp[1]-temp[0]){
                    res[i]=false;
                    break;
                }
            }
        }
        return res;
    }
};