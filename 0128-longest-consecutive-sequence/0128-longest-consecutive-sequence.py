class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hash = {}
        for i in range(len(nums)):
            hash[nums[i]] = 1
        
        ans = 0
        for i in hash.keys():
            if hash.get(i-1,0) == 0: 
                y =  i + 1
                while hash.get(y,0) !=0 : 
                    y = y + 1
                ans = max(ans , y - i)
        return ans 


        