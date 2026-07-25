class Solution {
public:
    int maxProduct(int n) {
        int maxi1=INT_MIN,maxi2=INT_MIN;
        bool ch = false;
        while(n){
            int curr = n%10;
            n/=10;
            if(maxi1 < curr){ maxi2 = maxi1; maxi1 = curr;}
            else if(maxi2 < curr) maxi2 = curr;
        }
        cout<<maxi1<<" "<<maxi2<<endl;
        return maxi1*maxi2;
    }
};