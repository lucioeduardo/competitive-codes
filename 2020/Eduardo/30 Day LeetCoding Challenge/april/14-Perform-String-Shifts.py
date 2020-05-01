class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        sh=0
        for a,b in shift:
            if(a):
                sh += b
            else:
                sh -= b
        sh %= len(s)
        
        ini = ""
        
        if(sh > 0):
            res = s[len(s)-sh:] + s[:len(s)-sh]
        else:
            res = s[sh:] + s[:sh]
            
        
        return res