class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n=a.size();
        // fill the intersection element begin from a.begin()
        auto it=set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin());
        a.erase(it, a.end());
        // for(int i=0;i<a.size();++i)
        //     cout << a[i] ;
        // cout << "\n";
        // for(int i=0;i<n;++i)
        //     cout << a[i] ;
        // cout << "\n";
        return a;
    }
};