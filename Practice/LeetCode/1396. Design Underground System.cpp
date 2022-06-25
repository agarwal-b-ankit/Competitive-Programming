class UndergroundSystem {
private:
    unordered_map<int, pair<string,int>> checkInMap;
    map<pair<string,string>,pair<double,int>> averageMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,string> key = {checkInMap[id].first,stationName};
        int time = t-checkInMap[id].second;
        if(averageMap.find(key)==averageMap.end()) averageMap[key]={(double)time, 1};
        else{
            double totalTime = averageMap[key].first*averageMap[key].second + time;
            int totalCnt = averageMap[key].second+1;
            averageMap[key]={totalTime/totalCnt, totalCnt};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return averageMap[{startStation,endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */