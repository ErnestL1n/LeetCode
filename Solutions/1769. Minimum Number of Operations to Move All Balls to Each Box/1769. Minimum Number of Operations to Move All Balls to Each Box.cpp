class Solution {
public:
    vector<int> minOperations(string boxes) {
        int cnt[2000]={};
        vector<int> res;
        for(int i=0;i<boxes.size();++i)
            if(boxes[i]=='1')
                cnt[i]=i+1;
        for(int i=0;i<boxes.size();++i){
            int tmp=0;
            for(int j=0;j<2000;++j)
                if(cnt[j])
                    tmp+=abs((i+1)-cnt[j]);
            res.push_back(tmp);
        }
        return res;
    }
};