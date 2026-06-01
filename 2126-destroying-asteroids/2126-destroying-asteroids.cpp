class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long x = mass;
       sort(asteroids.begin(),asteroids.end());
       for(int i=0;i<asteroids.size();i++){
        if(x<asteroids[i]) return false;
        else x+=asteroids[i];
       } 
       return true;
    }
};