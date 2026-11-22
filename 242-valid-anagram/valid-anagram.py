class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq = {}
        for ch in s:
            freq[ch] = freq.get(ch,0)+1
        for ch in t:
            freq[ch] = freq.get(ch,0)-1
        return all(count == 0 for count in freq.values())