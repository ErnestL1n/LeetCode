class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it=s.find(val);
        if(it==s.end()){
            s.insert(val);
            return true;
        }
        return false;   
    }
    
    bool remove(int val) {
        auto it=s.find(val);
        if(it!=s.end()){
            s.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto r=rand()%s.size();
        return *next(s.begin(),r);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */