class Solution {
public:
    int integerBreak(int n) {
        long long ans = 1;
        if(n == 2) return 1;
        else if(n == 3) return 2;

       while(n > 0 ){
        if(n==4 || n == 2){n-=2; ans *=2;}
        else {
            n-=3;
            ans*=3;
        }
        cout<<n<<endl;
       }
       return ans;
    }
};