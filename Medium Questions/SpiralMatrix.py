# Same logic as loop version but much cleaner:

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        spiral = []
        row, col = len(matrix), len(matrix[0])
        bottomRow, rightCol = row - 1, col - 1
        topRow = leftCol = 0
        
        while len(spiral) < row * col:
            for i in range(leftCol, rightCol + 1):
                spiral.append(matrix[topRow][i])
            
            for i in range(topRow + 1,bottomRow + 1):
                spiral.append(matrix[i][rightCol])
            
            if bottomRow != topRow:
                for i in range(rightCol - 1, leftCol - 1, -1):
                    spiral.append(matrix[bottomRow][i])
            
            if leftCol != rightCol:
                for i in range(bottomRow - 1, topRow, -1):
                    spiral.append(matrix[i][leftCol])

            topRow += 1
            rightCol -= 1
            bottomRow -= 1
            leftCol += 1
                        
        return spiral

# Initial loop solution:

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        spiral = []
        bottomRow, rightCol = len(matrix), len(matrix[0])
        topRow = leftCol = 0
        rowCol = 1
        down, right = 1, 1
        
        rowOffset = colOffset = 0
        if rightCol > bottomRow:
            colOffset = rightCol - bottomRow
        elif bottomRow > rightCol:
            rowOffset = bottomRow - rightCol
        
        while not (topRow + rowOffset == bottomRow and rightCol == leftCol + colOffset):
            if rowCol == 0:
                if down:
                    for i in range(topRow,bottomRow):
                        spiral.append(matrix[i][rightCol - 1])
                    rightCol -= 1
                    rowCol = 1
                    down = 0
                else:
                    for i in range(bottomRow - 1, topRow - 1, -1):
                        spiral.append(matrix[i][leftCol])
                    leftCol += 1
                    rowCol = 1
                    down = 1
                    
            else:
                if right:
                    for i in range(leftCol, rightCol):
                        spiral.append(matrix[topRow][i])
                    topRow += 1
                    rowCol = 0
                    right = 0
                else:
                    for i in range(rightCol - 1, leftCol - 1, -1):
                        spiral.append(matrix[bottomRow - 1][i])
                    bottomRow -= 1
                    rowCol = 0
                    right = 1
                        
        return spiral