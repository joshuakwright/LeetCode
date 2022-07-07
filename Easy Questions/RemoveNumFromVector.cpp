//My original solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != val) {
                    nums.at(j++) = nums.at(i);
            }
        }
        return j;
    }
};

//Slightly faster solution that swaps current with last if val, reducing array size by 1 each time, 
//and then checks to see if swapped element is val, if not, increments to next element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums.at(i) == val) {
                nums.at(i) = nums.at(n - 1);
                n--;
            } 
            else {
                i++;
            }
        }
        return n;
    }
};