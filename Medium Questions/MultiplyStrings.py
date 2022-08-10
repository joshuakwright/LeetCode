# Initial solution: 

class Solution(object):
    def multiplyStep(self, num1, num2, zeroes, maxLen):
        num1Len = len(num1) - 1
        carry = 0
        ans = ""
        for i in range(num1Len, -1, -1):
            temp = (ord(num1[i]) - ord('0')) * (ord(num2) - ord('0')) + carry
            carry = temp / 10
            ans = str(temp % 10) + ans
        
        if carry:
            ans = str(carry) + ans
        ans +=  '0' * zeroes
        
        ans = (maxLen - len(ans)) * '0' + ans
        
        return ans
    
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1[0] == '0' or num2[0] == '0':
            return '0'
        
        stepNums = []
        num2Len = len(num2) - 1
        maxLen = len(num1) + len(num2)
        for i in range(num2Len, -1, -1):
            stepNums.append(self.multiplyStep(num1, num2[i], num2Len - i, maxLen))
            
        carry = 0
        output = ""
        for i in range(maxLen - 1, -1, -1):
            temp = 0
            for j in range(len(stepNums)):
                temp += ord(stepNums[j][i]) - ord('0')
            temp += carry
            carry = temp / 10
            output = str(temp % 10) + output
        
        if carry:
            output[0] = str(carry)
            
        return output if output[0] != '0' else output[1:]