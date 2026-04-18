class Solution {
public:
int reverse(int n){
        int ans{},powe  = 0, dupe = n;
        while(n/(long long )pow(10,powe) !=0){  powe++;}

        powe --;
        //cout<< powe<<endl;
        while(n){
            ans += ((n%10) * pow(10,powe));
            powe--;
            n/=10;
        }
    return ans;
    }
    int mirrorDistance(int n) {
        return abs(reverse(n) - n);
    }
};