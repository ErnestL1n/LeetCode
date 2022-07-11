class SmallestInfiniteSet {
public:
    vector<bool> v;
    SmallestInfiniteSet() {
        v=vector<bool>(1001);
        for(int i=1;i<1001;++i){
            v[i]=1;
        }
    }
    
    int popSmallest() {
        int i=1;
        while(v[i]!=1){
            ++i;
        }
        v[i]=0;
        return i;
    }
    
    void addBack(int num) {
        v[num]=1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */