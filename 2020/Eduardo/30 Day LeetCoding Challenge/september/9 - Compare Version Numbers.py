class Solution(object):
    def compareVersion(self, version1, version2):
        v1 = map(int, version1.split('.'))
        v2 = map(int, version2.split('.'))
        
        m = max(len(v1),len(v2))
        
        while len(v1) < m:
            v1.append(0)
        while len(v2) < m:
            v2.append(0)
        
        res = 0
        
        for i in range(m):
            if(v1[i] < v2[i]):
                res=-1
                break
            elif(v2[i] < v1[i]):
                res=1
                break
        
        return res
        
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        