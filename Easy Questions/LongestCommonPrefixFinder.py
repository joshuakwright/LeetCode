# Initial solution using column scanning method

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        comPre = ""
        index = 0
        while True:
            for i in range(len(strs)):
                if index >= len(strs[i]) or strs[i][index] != strs[0][index]:
                    return comPre
            comPre += strs[0][index]
            index += 1
        
            