# Initial quick solution using DP:

class Solution(object):
    def findBall(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        rowLen, colLen = len(grid), len(grid[0])
        
        ans = []
        for col in range(colLen):
            stuck = 0
            level = 0
            cCol = col
            while level < rowLen and stuck == 0:
                if grid[level][cCol] == -1:
                    if cCol - 1 < 0 or grid[level][cCol - 1] == 1:
                        stuck = 1
                    else:
                        cCol -= 1
                else:
                    if cCol + 1 >= colLen or grid[level][cCol + 1] == -1:
                        stuck = 1
                    else:
                        cCol += 1
                        
                level += 1
            
            if stuck:
                ans.append(-1)
            else:
                ans.append(cCol)
                
        return ans