class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size()<=1){
            if(nums.size()==0)
                return res;
            res.push_back(to_string(nums[0]));
            return res;
        }
        nums.push_back(0);
        long head=nums[0],tail=nums[0];
        for(int i=1;i<nums.size();++i){
            while(tail+1==nums[i])
                ++tail,++i;
            if(tail==head)
                res.push_back(to_string(head));
            else
                res.push_back(to_string(head)+"->"+to_string(tail));
            tail=head=nums[i];
            //cout << head <<"\n";
        }
        return res;
    }
};