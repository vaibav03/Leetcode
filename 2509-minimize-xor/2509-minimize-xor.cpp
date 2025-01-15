class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setbits2 = __builtin_popcount(num2),setbits = __builtin_popcount(num1);
        int ans{};
        if(setbits2>=setbits){
            ans = num1;
            setbits2-=setbits;
            int i = 0;
            while(setbits2){
                if( !(1<<i&num1) ){
                    ans|=(1<<i);
                    setbits2--;
                }
                i++;
            }
        }
        else{
            int i = 31;
            while(setbits2){
             if ((num1)& (1<<i))
             {
                ans|=1<<i;
                setbits2--;
             }   
             i--;
            }
        }
        return ans;

    }
};