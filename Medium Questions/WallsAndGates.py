//Fast solution using breadth first search but starting from the gates

class Solution(object):
    EMPTY = 2147483647
    GATE = 0
    DIRECTIONS = [[1,0],[-1,0],[0,1],[0,-1]]
    
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
        m = len(rooms)
        if m == 0: return
        n = len(rooms[0])
        
        queue = []
        for row in range(0, m):
            for col in range(0, n):
                if(rooms[row][col] == self.GATE):
                    queue.append([row, col])
                    
        while len(queue) != 0:
            point = queue.pop(0)
            row = point[0]
            col = point[1]
            
            for direction in self.DIRECTIONS:
                r = row + direction[0]
                c = col + direction[1]
                if r < 0 or c < 0 or r >= m or c >= n or rooms[r][c] != self.EMPTY:
                    continue
                    
                rooms[r][c] = rooms[row][col] + 1
                queue.append([r, c])

//Initial too slow version using breadth first search starting from each empty square going to the gate

class Solution(object):
    EMPTY = 2147483647
    GATE = 0
    WALL = -1
    DIRECTIONS = [[1,0],[-1,0],[0,1],[0,-1]]
    
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
        if len(rooms) == 0: return
        for row in range(0, len(rooms)):
            for col in range(0, len(rooms[0])):
                if(rooms[row][col] == self.EMPTY):
                    rooms[row][col] = self.distanceToNearestGate(rooms, row, col)
                    
    def distanceToNearestGate(self, rooms, startRow, startCol):
        m = len(rooms)
        n = len(rooms[0])
        distance = [[0 for x in range(n)] for x in range(m)]
        queue = [[startRow, startCol]]
        while len(queue) is not 0:
            point = queue.pop(0)
            row = point[0]
            col = point[1]
            for direction in self.DIRECTIONS:
                r = row + direction[0]
                c = col + direction[1]

                if r < 0 or c < 0 or r >= m or c >= n or rooms[r][c] == self.WALL \
                or distance[r][c] != 0:
                    continue
                    
                distance[r][c] = distance[row][col] + 1
                
                if rooms[r][c] == self.GATE:
                    return distance[r][c]
                
                queue.append([r, c])
        
        return 2147483647