class RideSharingSystem {
public:
queue<int> riders, drivers;
set<int> rideSet,cancel;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        rideSet.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!riders.empty() && !drivers.empty()){
            int topR = riders.front(),topD = drivers.front();
            if(cancel.find(topR) == cancel.end()){
                riders.pop();
                rideSet.erase(topR);
                drivers.pop();
                return {topD,topR};
            }else{
                cancel.erase(topR);
                rideSet.erase(topR);
                riders.pop();
            }
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        if(rideSet.find(riderId) != rideSet.end()) cancel.insert(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */