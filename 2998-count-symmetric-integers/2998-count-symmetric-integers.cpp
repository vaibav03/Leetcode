class Solution {
public:
    bool isSymmetric(int x){
        int tens{},num = x;
        string s;
        while(num){
            tens++;
            s+=(num%10);
            num/=10;
        }
        if(tens%2) return 0;
        
        reverse(s.begin(),s.end());

        int  sum1{},sum2{},i{};
        while(i<tens/2){
            sum1+= (s[i]-'0');
            sum2+= (s[tens-i-1] - '0');
            i++;
        }

        return sum1==sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans{};
        for(int i=low;i<=high;i++){
            ans+=isSymmetric(i);
            if(isSymmetric(i))
            cout<<i<<" ";
        }
        return ans;
    }
};