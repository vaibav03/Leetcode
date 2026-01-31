class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if bisect_right(letters,target) >= len(letters):
            return letters[0]
        return letters[bisect_right(letters,target)]