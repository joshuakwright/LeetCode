# Initial recursive solution

class Solution(object):
    def decode(self, s):
        inter = ""
        i = 0
        while i < len(s):
            if s[i] >'0' and s[i] <= '9':
                mult = s[i]
                i += 1
                while s[i] >='0' and s[i] <= '9':
                    mult += s[i]
                    i += 1
                i -= 1

                stack = []
                stack.append('[')
                j = i + 2
                while stack:
                    if s[j] == '[':
                        stack.append('[')
                    elif s[j] == ']':
                        stack.pop()
                    j += 1
                interStr = self.decode(s[i + 2:j - 1])
                for k in range(int(mult)):
                    inter += interStr
                i = j
            else:
                inter += s[i]
                i += 1
            
        
        return inter
                        
    
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return self.decode(s)