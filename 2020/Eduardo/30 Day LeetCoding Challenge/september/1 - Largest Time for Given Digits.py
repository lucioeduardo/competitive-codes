class Solution:
    def grt(self, a, b):
        if(b == ""):
            return True
        
        hA, mA = map(int, a.split(':'))
        hB, mB = map(int, b.split(':'))
                
        return (60*hA + mA) > (60*hB + mB)
    
    def largestTimeFromDigits(self, A: List[int]) -> str:
        l = len(A)
        
        res = ""
        
        x = ord('0')
        
        for a in range(l):
            for b in range(l):
                if(a == b):
                    continue
                for c in range(l):
                    if(a == c or b == c):
                        continue
                    for d in range(l):
                        if(a == d or b == d or c == d):
                            continue
                            
                        k = A[a]
                        y = A[b]
                        z = A[c]
                        w = A[d]
                        
                        if(k>2 or z>5 or (k==2 and y>3)):
                            continue
                        
                        s = chr(x+k)+chr(x+y)+":"+chr(x+z)+chr(x+w)
                        
                        print(s)
                        if(self.grt(s,res)):
                            res=s
        return res