#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Use a max-heap (priority queue)
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        
        // Modify the largest k gifts
        for (int i = 0; i < k; i++) {
            int largest = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(floor(sqrt(largest)));
        }
        
        // Calculate the total sum of remaining gifts
        long long totalSum = 0;
        while (!maxHeap.empty()) {
            totalSum += maxHeap.top();
            maxHeap.pop();
        }
        
        return totalSum;
    }
};
