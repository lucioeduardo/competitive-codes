class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split()
        res = ""
        add = "a"
        
        for word in words:
            if(word[0] in 'aeiouAEIOU'):
                word += 'ma'
            else:
                word = word[1:] + word[0] + 'ma'
            word += add
            add += 'a'
            res += word + ' '
        
        return res[:len(res)-1]