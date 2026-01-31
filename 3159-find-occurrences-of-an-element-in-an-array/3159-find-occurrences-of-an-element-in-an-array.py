class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        pos = []
        for i in range(len(nums)):
            if nums[i] == x:
                pos.append(i)
        ans = []
        for i in queries:
                ans.append(-1 if i> len(pos) else pos[i-1])
        return ans