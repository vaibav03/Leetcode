class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = {}
        for word in words: 
            cnt[word] = cnt.get(word, 0) + 1
        arr = []
        for word,c in cnt.items():
            arr.append([c,word])
        
        arr.sort(key = lambda x : (-x[0],x[1]))
        return [word for _,word in arr[0:k]]

        

        
                
                
                
                

