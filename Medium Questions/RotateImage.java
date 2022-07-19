//Fast solution

class Solution {
    public void rotate(int[][] matrix) {
        int size = matrix.length;
        for(int i = 0; i < (size + 1) / 2; i++) {
            for(int j = 0; j < size / 2; j++) {
                int temp = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
                matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
                matrix[j][size - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
}

//Solution using common matrix operation but much slower

class Solution {
    public void rotate(int[][] matrix) {
        transposeUpLine(matrix);
        reverseVertical(matrix);
    }
    
    public void transposeUpLine(int[][] matrix) {
        int size = matrix.length;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size - i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[size - 1 - j][size - 1 - i];
                matrix[size - 1 - j][size - 1 - i] = temp;
            }
        }
    }
    
    public void reverseVertical(int[][] matrix) {
        int size = matrix.length;
        for(int i = 0; i < size / 2; i++) {
            for(int j = 0; j < size; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[size - 1 - i][j];
                matrix[size - 1 - i][j] = temp;
            }
        }
    }
}

//All my broken first attemps, none will go past 6x6 correctly

class Solution {
    public void rotate(int[][] matrix) {
        int size = matrix.length;
        int rings = (int)Math.ceil(size / 2d);
        
        for(int j = 0; j < rings; j++) {
            int ringSize = size - j * 2;
            
            int[] temp = new int[ringSize];
            for(int i = 0 + j; i < ringSize; i++) {
                temp[i] = matrix[i][size - 1 - j];
                if(i < size - 1 - j) {
                    matrix[i][size - 1 - j] = matrix[0 + j][i];
                    matrix[0 + j][i] = matrix[size - i - 1][0 + j];
                }
            }
            
            if (ringSize != size && ringSize == 2) ringSize += 1;
            else if (ringSize % 2 == 1) ringSize += j;
            for(int i = 1 + j; i < ringSize; i++) {
                matrix[i][0 + j] = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = temp[size - i - 1];
            }        
        }
    }
}

class Solution {
    public void rotate(int[][] matrix) {
        int size = matrix.length;
        int rings = (int)Math.ceil(size / 2d);
        
        for(int j = 0; j < rings; j++) {
            int ringSize = size - j * 2;
            
            int[] temp = new int[ringSize];
            for(int i = 0 + j; i < ringSize; i++) {
                temp[i] = matrix[i][size - 1 - j];
                if(i < size - 1 - j) {
                    matrix[i][size - 1 - j] = matrix[0 + j][i];
                    matrix[0 + j][i] = matrix[size - i - 1][0 + j];
                }
            }            
            for(int i = 1 + j; i < ringSize + j; i++) {
                matrix[i][0 + j] = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = temp[size - i - 1];
            }        
        }
    }
}

class Solution {
    public void rotate(int[][] matrix) {
        int size = matrix.length;
        int rings = (int)Math.ceil(size / 2d);
        
        for(int j = 0; j < rings; j++) {
            int ringSize = size - j * 2;
            
            int[] temp = matrix[0 + j].clone();   
            for(int i = 0 + j; i < ringSize; i++) {
                matrix[0 + j][i] = matrix[size - i - 1][0 + j];
            }            
            matrix[0 + j][size - 1 - j] = temp[0 + j];
            for(int i = 1 + j; i < ringSize + j; i++) {
                matrix[i][0 + j] = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = matrix[i][size - 1 - j];
                matrix[i][size - 1 - j] = temp[i];
            }        
        }
    }
}

        /*matrix[0][3] = matrix[0][0];
        matrix[0][2] = matrix[1][0];
        matrix[0][1] = matrix[2][0];
        matrix[0][0] = matrix[3][0];
        
        matrix[i + 1][j + 1] = matrix[i + 2][j + 1];
        matrix[i + 2][j + 1] = matrix[i + 2][j + 2];
        matrix[i + 1][j + 2] = matrix[i + 1][j + 1];
        matrix[i + 2][j + 2] = matrix[i + 1][j + 2];*/