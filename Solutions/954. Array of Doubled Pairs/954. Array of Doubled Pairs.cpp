class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> m;
        for(const auto& a:arr)
            ++m[a];
        vector<int> keys;
        for(const auto& [k,v]:m)
            keys.push_back(k);
        sort(keys.begin(),keys.end(),[](int i,int j){return abs(i)<abs(j);});
        for(int k:keys){
            cout << k <<"  "<< m[k] <<"  " << m[2*k] <<"\n";
            if(m[k]>m[k*2])
                return false;
            m[k*2]-=m[k];
        }
        return true;
    }
};