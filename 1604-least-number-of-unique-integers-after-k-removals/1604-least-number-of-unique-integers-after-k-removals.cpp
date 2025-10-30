class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> occ;
        int val = arr[0],i{};
        while(i<arr.size()){
            int l =i;
            val = arr[i];
            while(i<arr.size() && val == arr[i]) i++; 
            occ.push_back(i - l);
        }
        sort(occ.begin(),occ.end());
        i=0;
        while(i<occ.size() && k>0){
            if(k>=occ[i])
            {k-=occ[i];
            i++;} else break;
        }
        return occ.size() - i;
    }
};