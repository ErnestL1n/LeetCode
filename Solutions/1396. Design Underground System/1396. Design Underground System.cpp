class UndergroundSystem {
public:
    // id-{stationName,Time}
    unordered_map<int,pair<string,int>> checkin;
    // road-{duration,count}
    unordered_map<string,pair<int,int>> checkout;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& in=checkin[id];
        string road=in.first+"-"+stationName;
        checkout[road].first+=t-in.second;
        checkout[road].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string road=startStation+"-"+endStation;
        auto& getduration=checkout[road];
        return (double)getduration.first/getduration.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */