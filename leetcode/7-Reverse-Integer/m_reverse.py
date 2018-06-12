
class Solution(object):
    def reverse_abs(self, x):
        prefix = []
        while x != 0:
            prefix.append(x % 10)
            x = x / 10
            
        prefix.reverse()
        x = 0
        for i in range(len(prefix)):
            x += prefix[i] * pow(10, i)
            
        return x
    
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        negative = False
        abs_value = 0
        
        if x == 0:
            return 0
        elif x < 0:
            negative = True
            abs_value = self.reverse_abs(abs(x))
        else:
            abs_value = self.reverse_abs(x)
        
        recovery = lambda x:x if negative is False else -1*x
        
        ret = recovery(abs_value)
        
        if ret < -pow(2,31) or ret > pow(2, 31) - 1:
            return 0
        else:
            return ret

