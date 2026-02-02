class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dist = []
        for x,y in points:
            dist.append([x**2 + y**2, x,y])
        
        dist.sort()

        ans = []
        for i in range(k):
            ans.append([dist[i][1], dist[i][2]])
        
        return ans