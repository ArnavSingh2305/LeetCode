class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mp = {}
        for i in range(len(strs)):
            newWord = strs[i]
            key = ''.join(sorted(newWord))
            if key not in mp:
                mp[key] = []
            mp[key].append(strs[i])
        a = []
        for values in mp.values():
            a.append(values)
        return a 