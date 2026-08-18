from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp = Counter(magazine)

        for ch in ransomNote:
            if mp[ch] == 0:
                return False
            mp[ch] -= 1

        return True