// Fast working solution using greedy enumeration

class Solution {
    set<int> squares;
    
    bool isDividedBy(int n, int count) {
        if(count == 1) {
            return squares.count(n);
        }
        
        for(auto square : squares) {
            if (isDividedBy(n - square, count - 1)) {
                return true;
            }
        }
        return false;
    }
    
public:
    int numSquares(int n) {
        int square = 1;
        for (int num = 1; square <= n; num++) {
            squares.insert(square);
            square = num * num;
        }
        
        for(int count = 1; count <= n; count++) {
            if(isDividedBy(n, count)){
                return count;
            }
        }
        
        return 0;
    }
};