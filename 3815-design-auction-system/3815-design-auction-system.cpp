class AuctionSystem {
public:
unordered_map<int, map<int,int> > M;
unordered_map<int,set<pair<int,int>>> s;
    AuctionSystem() {
        
    }
    
    void addBid(int u, int i, int b) {
        if(M[i].count(u) ){
            auto it = s[i].find({M[i][u] , u});
            s[i].erase(it);
        }
        M[i][u] = b;
        s[i].insert({b , u});    
    }
    
    void updateBid(int u, int i, int newAmount) {
        auto it = s[i].find({M[i][u] , u});
        s[i].erase(it);
        M[i][u] = newAmount;
        s[i].insert({newAmount, u});
    }
    
    void removeBid(int u, int i) {
        auto it = s[i].find({M[i][u] , u});
        s[i].erase(it);
        M[i].erase(u);
    }
    
    int getHighestBidder(int itemId) {
        if(s[itemId].empty()) return -1;

        auto it  = s[itemId].rbegin();
        return it->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */