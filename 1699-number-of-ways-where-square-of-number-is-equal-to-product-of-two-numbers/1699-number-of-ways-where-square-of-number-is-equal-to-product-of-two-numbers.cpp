class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long,long long> m1,m2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]*nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]*nums2[i]]++;
        }   
    int ans{};
        for(int i=0;i<nums1.size();i++){
            for(int j=i+1;j<nums1.size();j++){
                ans+=m2[nums1[i]*nums1[j]];
            }
        }
    for(int i=0;i<nums2.size();i++){
            for(int j=i+1;j<nums2.size();j++){
                ans+=m1[nums2[i]*nums2[j]];
            }
        }
    return ans;
    }
};