class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> hash(A.size()+1,0), C(A.size(),0);
        for(int i=0;i<A.size();i++){
            hash[A[i]]++;
            hash[B[i]]++;
            int toadd;
            if(A[i]!=B[i])
            toadd = hash[A[i]]/2 +hash[B[i]]/2;
            else
            toadd = hash[A[i]]/2;

            if(i)
            C[i] = C[i-1]+toadd;
            else
            C[i] = toadd;
        }
        return C;
    }
};