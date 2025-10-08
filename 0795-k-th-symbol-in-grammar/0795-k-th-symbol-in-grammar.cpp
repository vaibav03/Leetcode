class Solution {
public:
    int solve(int n,int k){
        if(n == 2 ) return (k==1) ? 0 : 1;
        if(n==1) return 0;
        int back ;
        if(k%2 == 1) back = (k+1)/2;
        else back = k/2;

        if(solve(n-1,back) == 1){
            return (k%2==1) ? 1 : 0;
        }else{
            return (k%2==1) ? 0 : 1;
        }
        
    }
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};