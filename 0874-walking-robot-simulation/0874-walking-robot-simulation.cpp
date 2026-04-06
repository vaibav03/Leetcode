class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> directions = {{0,1}, {1,0},{0,-1},{-1,0}};
        long long ans{};
        int ind{},x{},y{};
        set<pair<int,int>> obs;
        for(auto o : obstacles){
            obs.insert({o[0],o[1]});
        }
        for(int i=0;i<commands.size();i++){
            if(commands[i] == -1){
                ind = (ind+1)%4;
            }else if(commands[i] == -2){
                ind = (ind + 3)%4;
            }else{
                int dx = directions[ind][0] , dy = directions[ind][1];
                for(int f=1;f<=commands[i];f++){
                    int nx = x +dx , ny = y +dy;
                    if(obs.find({nx,ny}) != obs.end()) break;
                    else {
                        x = nx;
                        y = ny;
                        cout<<x<<" "<<y<<endl;
                        ans = max(ans, nx*1ll*nx + ny*1ll*ny);
                    }
                }
            }
        }
        return ans;
    }
};