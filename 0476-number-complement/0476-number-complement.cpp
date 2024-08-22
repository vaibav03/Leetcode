class Solution {
public:
    int findComplement(int num) {
        int i=0;
        int msb=0,num1=num;
        while(num1>>msb){
            msb++;
        }

        while(i<msb){
            if(num&(1<<i)){
               num-=(1<<i); 
            }
            else
            {
              num+=(1<<i);  
            }

            i++;
        }
        return num;

    }
};