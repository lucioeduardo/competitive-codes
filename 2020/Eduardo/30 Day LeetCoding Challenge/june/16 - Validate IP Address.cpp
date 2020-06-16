class Solution:
    
    def validDecimalNumber(self,n):
        return n in "0123456789"
    
    def validHexNumber(self,n):
        return self.validDecimalNumber(n) or n in "abcdefABCDEF"
    
    
    def validIPAddress(self, IP: str) -> str:
        if('.' in IP):
            nums = IP.split('.')
            if(len(nums) != 4):
                return "Neither"
            for i in nums:
                if(len(i) == 0):
                    return "Neither"
                for c in i:
                    if not self.validDecimalNumber(c):
                        return "Neither"
                if(not(int(i) >=0 and int(i) <= 255) or len(str(int(i))) != len(i)):
                    return "Neither"
            return "IPv4"
        else:
            nums = IP.split(':')            
            if(len(nums) != 8):
                return "Neither"
            for i in nums:
                if(len(i) == 0):
                    return "Neither"
                for c in i:
                    if not self.validHexNumber(c):
                        return "Neither"
                if(not(int(i,16) >=0 and int(i,16) <= 0xffff) or len(i)>4):
                    return "Neither"
            return "IPv6"