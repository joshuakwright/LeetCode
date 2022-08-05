# Iterative bredth first solution:

class Solution(object):                 
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        rowLen = len(image)
        colLen = len(image[0])
        iniColor = image[sr][sc]
        if iniColor == color:
            return image

        queue = deque([(sr, sc)])
        while queue:
            row, col = queue.popleft()
            if image[row][col] == iniColor:
                image[row][col] = color
                if row - 1 >= 0:
                    queue.append((row-1, col))
                if row + 1 < rowLen:
                    queue.append((row+1, col))
                if col - 1 >= 0:
                    queue.append((row, col-1))
                if col + 1 < colLen:
                    queue.append((row, col+1))

        return image

# Initial recursive depth first solution:

class Solution(object): 
    def flood(self, image, sr, sc, color):
        rowLen = len(image)
        colLen = len(image[0])
        
        if sr - 1 >= 0 and image[sr - 1][sc] == self.iniColor:
            image[sr - 1][sc] = color
            self.flood(image, sr - 1, sc, color)
        if sr + 1 < rowLen and image[sr + 1][sc] == self.iniColor:
            image[sr + 1][sc] = color
            self.flood(image, sr + 1, sc, color)
        if sc - 1 >= 0 and image[sr][sc - 1] == self.iniColor:
            image[sr][sc - 1] = color
            self.flood(image, sr, sc - 1, color)
        if sc + 1 < colLen and image[sr][sc + 1] == self.iniColor:
            image[sr][sc + 1] = color
            self.flood(image, sr, sc + 1, color)
                
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        self.iniColor = image[sr][sc]
        if self.iniColor == color:
            return image
        
        image[sr][sc] = color
        self.flood(image, sr, sc, color)
        return image