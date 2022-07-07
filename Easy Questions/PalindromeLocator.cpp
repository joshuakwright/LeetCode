//My stupidly overcoded, overengineered, super slow algorithm to find palindromes (but it does work)
class Solution {
public:
    bool isPalindrome(int x) {
        int size = 0;
        int temp = x;
        bool ans;
        int pop;
        while (temp != 0) {
            temp /= 10;
            size++;
        }
        
        if (x < 0) {
            return false;
        }
        if (x >=0 && x <=9) {
            return true;
        }
     
        if (size % 2 == 1) {
            vector<vector<int>> pal(2, vector<int>(size/2, 0));
            for (int i = 0; i < size/2; i++) {
                pop = x % 10;
                x /= 10;
                pal[0][i] = pop;
            }
            
            x /= 10;
            for (int i = size/2; i != 0; i--) {
                pop = x %10;
                x /=10;
                pal[1][i-1] = pop;
            }
            
            for (int i = 0; i < size/2; i++) {
                if (pal[0][i] == pal[1][i]) {
                    ans = true;
                }
                else if(pal[0][i] != pal[1][i]) {
                    return false;
                }
            }
        }
        
        else if (size % 2 == 0) {
            vector<vector<int>> pal(2, vector<int>(size/2, 0));
            for (int i = 0; i < size/2; i++) {
                pop = x % 10;
                x /= 10;
                pal[0][i] = pop;
            }
            
            for (int i = size/2; i != 0; i--) {
                pop = x %10;
                x /=10;
                pal[1][i-1] = pop;
            }
            
            for (int i = 0; i < size/2; i++) {
                if (pal[0][i] == pal[1][i]) {
                    ans = true;
                }
                else if(pal[0][i] != pal[1][i]) {
                    return false;
                }
            }
        }
        
        return ans;
    }
};

//the elegantly crafted much faster way to find a palindrome
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int rev = 0;
        while (x > rev) {
            rev = rev*10 + x % 10;
            x /= 10;
        }
        
        return x == rev || x == rev / 10;
    }
};