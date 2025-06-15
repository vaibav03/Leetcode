class Solution {
public:

    int maxDiff(int num) {
        int temp = num;
        string numString = to_string(num); 
        int greatestNum{}, smallestNum{},n = numString.size();
        if(numString[0]!='9' && numString[0]!='1'){
            for(int i=0;i<n;i++){
                if(numString[i]==numString[0])
                greatestNum+=((9)*pow(10,n-i-1));
                else
                greatestNum+=((numString[i]-'0')*pow(10,n-i-1));
            }
            for(int i=0;i<n;i++){
                if(numString[i]==numString[0])
                smallestNum+=((1)*pow(10,n-i-1));
                else
                smallestNum+=((numString[i]-'0')*pow(10,n-i-1));
            }
            return greatestNum - smallestNum;
        }else{
            if(numString[0]=='9'){
                int ind{};
                while(numString[ind]=='9'){
                    ind++;
                }
                for(int i=0;i<n;i++){
                if(numString[i]==numString[ind])
                greatestNum+=((9)*pow(10,n-i-1));
                else
                greatestNum+=((numString[i]-'0')*pow(10,n-i-1));
            }
                for(int i=0;i<n;i++){
                if(numString[i]==numString[0])
                smallestNum+=((1)*pow(10,n-i-1));
                else
                smallestNum+=((numString[i]-'0')*pow(10,n-i-1));
                }
            return greatestNum - smallestNum;

            } else{
                int ind{};
                while(numString[ind]=='1' || numString[ind]=='0'){
                    ind++;
                }
                cout<<ind<<endl;
                for(int i=0;i<n;i++){
                if(numString[i]==numString[0])
                greatestNum+=((9)*pow(10,n-i-1));
                else
                greatestNum+=((numString[i]-'0')*pow(10,n-i-1));
            }
            for(int i=0;i<n;i++){
                if(numString[i]==numString[ind])
                smallestNum+=((0)*pow(10,n-i-1));
                else
                smallestNum+=((numString[i]-'0')*pow(10,n-i-1));
                }
                cout<<greatestNum << " "<<smallestNum<<endl;
        return greatestNum - smallestNum;
            }
        }

    }
};