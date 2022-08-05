# breadth first iterative solution:

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        islands = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1":
                    islands += 1
                    grid[i][j] = 0
                    queue = deque([(i, j)])
                    while queue:
                        k, l = queue.popleft()
                        if k - 1 >= 0 and grid[k-1][l] == "1":
                            grid[k-1][l] = 0
                            queue.append((k - 1, l))
                        if k + 1 < row and grid[k+1][l] == "1":
                            grid[k+1][l] = 0
                            queue.append((k + 1, l))
                        if l - 1 >= 0 and grid[k][l-1] == "1":
                            grid[k][l-1] = 0
                            queue.append((k, l - 1))
                        if l + 1 < col and grid[k][l+1] == "1":
                            grid[k][l+1] = 0
                            queue.append((k, l + 1))
                            
        return islands

# recursive DFS initial fast solution

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
        
    