class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        # Counter(string).items() : 해당 string에 어떤 char이 몇번 나오는지 return as tuple type
        ransom_c = Counter(ransomNote)
        magazine_c = Counter(magazine)

        '''
        for char, n in ransom_c.items():
            if magazine_c[char] < n: ## 하나라도 안되는 게 있으면 False
                return False
        return True
        '''

        return ransom_c & magazine_c == ransom_c
        # &: 교집합 역할을 함. 교집합이 ransom_c와 같다는 것은 곧 ransom_c가 magazine_c에 고대로 있다는 뜻