//My initial fast solution

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] + 1 <= 9) {
                    digits[i]++;
                    break;
            }
            digits[i] = 0;
        }
        if(digits[0] == 0) digits.insert(digits.begin(), 1);
        
        return digits;
    }
};