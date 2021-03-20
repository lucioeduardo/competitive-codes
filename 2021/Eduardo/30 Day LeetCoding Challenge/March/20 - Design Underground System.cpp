#define pss pair<string,string>
#define psi pair<string,int>
#define pii pair<int,int>

class UndergroundSystem {
public:
    map<pss, pii> hist;
    map<int, psi> pos;
    
    UndergroundSystem() {
        hist.clear();
        pos.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        pos[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string prev = pos[id].first;
        
        pii val = hist[{prev,stationName}];
        val.first += t - pos[id].second;
        val.second++;

        hist[{prev,stationName}] = val;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pii val = hist[{startStation,endStation}];
                
        return (double)val.first/(double)val.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */