//initial fast solution

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        
        islands = 0
        height = len(grid)
        width = len(grid[0])
        
        for i in range(0, height):
            for j in range(0, width):
                if grid[i][j] == "1":
                    self.removeIsland(grid, i, j)
                    islands += 1
        
        return islands
    
    def removeIsland(self, grid, i, j):
        grid[i][j] = 0
        
        if i - 1 >= 0 and grid[i - 1][j] == "1":
            self.removeIsland(grid, i - 1, j)
        if i + 1 < len(grid) and grid[i + 1][j] == "1":
            self.removeIsland(grid, i + 1, j)
        if j - 1 >= 0 and grid[i][j - 1] == "1":
            self.removeIsland(grid, i, j - 1)
        if j + 1 < len(grid[0]) and grid[i][j + 1] == "1":
            self.removeIsland(grid, i, j + 1)
        
    