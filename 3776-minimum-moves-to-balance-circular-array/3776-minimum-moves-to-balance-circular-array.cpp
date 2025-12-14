class Solution {
public:
    long long minMoves(vector<int>& bal) {
        long long sum = accumulate(bal.begin(),bal.end(),0LL);
        int n = bal.size();
        if(sum < 0) return -1;

        int negInd = -1;
        for(int i=0;i<bal.size();i++){
            if(bal[i] < 0) negInd = i;
        }
        if(negInd == -1) return 0;

        long long ans = 0;
        long long stop =  abs(bal[negInd]),left = (negInd-1+n)%n, right = (negInd+1)%n;
      //  cout<<left<<" "<<right<<endl;
        while(stop != 0){

            long long pos = min( (bal[left] + bal[right])*1ll ,stop);
            stop-=pos;
            long long x = min(abs(negInd - left) , n - abs(negInd -  left)) ;
            bal[right] = 0;
            bal[left] = 0;
            left = (left - 1 + n ) % n;
            right = (right +1) % n;
            ans += pos*1ll*x;
        }
        return ans;
    }
};