class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1,inc = 1;
        while(time--){
            if(i == n){ inc = 0; i--; continue;}
            if(i == 1){ inc = 1; i++; continue;}
            if(inc){
                i++;
            }else{
                i--;
            }   
        }
        return i;
    }
};