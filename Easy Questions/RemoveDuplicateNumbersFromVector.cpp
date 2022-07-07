// My original solution (not too fast)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.at(i) == nums.at(i + 1)) {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i--;
            }
        }
        return nums.size();
    }
};

// Much faster solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums.at(j) != nums.at(i)) {
                i++;
                nums.at(i) = nums.at(j);
        }
    }
    return i + 1;
    }
};