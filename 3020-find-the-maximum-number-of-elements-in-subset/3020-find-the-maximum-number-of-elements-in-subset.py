class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        hash = {}
        for i in range(len(nums)):
            hash[nums[i]] = hash.get(nums[i],0) + 1
        ans = 1
        for i in hash.keys():
            pres = 0
            ch = i
            if i == 1:
                val = hash.get(i,0)
                ans = max(ans ,val if val%2 == 1 else val - 1)
                continue
            while hash.get(ch,0) >= 2:
                pres+=2
                ch = ch*ch
            if hash.get(ch,0) == 1:
                pres+=1
            else :
                pres -= 1
            ans = max(ans ,pres)
        
        return ans
            
