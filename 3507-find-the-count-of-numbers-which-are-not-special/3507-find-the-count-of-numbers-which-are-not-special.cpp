class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int sqrtl = ceil(sqrt(l)); 
        vector<int> v(sqrt(r)+1,1);
        v[0]=0;
        v[1]=0;
        for(int i=2;i<=sqrt(sqrt(r));i++)
        {
          if(v[i])
          {
           for(int j=i*i;j<=sqrt(r);j+=i){
            v[j]=0;
          }   
          }  
        }
        return r-l + 1 - accumulate(v.begin()+sqrtl,v.end(),0);
    }
};