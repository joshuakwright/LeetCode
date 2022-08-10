# Optimal one pass solution:

class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        secretMap = defaultdict(int)
        
        bulls = cows = 0
        for i, c in enumerate(secret):
            gc = guess[i]
            if c == gc:
                bulls += 1
            else:
                cows += int(secretMap[c] < 0) + int(secretMap[gc] > 0)
                secretMap[c] += 1
                secretMap[gc] -= 1
        
        return str(bulls) + "A" + str(cows) + "B"

# Cleaner version of two pass solution:

class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        secretMap = Counter(secret)
        
        bulls = cows = 0
        for i, c in enumerate(guess):
            if c in secretMap:
                if c == secret[i]:
                    bulls += 1
                    cows -= int(secretMap[c] <= 0)
                else:
                    cows += int(secretMap[c] > 0)
                secretMap[c] -= 1
        
        return str(bulls) + "A" + str(cows) + "B"

# Initial two pass solution:

class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        secretMap = {}
        for i, c in enumerate(secret):
            if c in secretMap.keys():
                secretMap[c] += 1
            else:
                secretMap[c] = 1
        
        bulls = cows = 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                if secretMap[guess[i]] <= 0:
                    cows -= 1
                bulls += 1
                secretMap[guess[i]] -= 1
            elif guess[i] in secretMap.keys() and secretMap[guess[i]] > 0:
                cows += 1
                secretMap[guess[i]] -= 1
        
        return str(bulls) + "A" + str(cows) + "B"