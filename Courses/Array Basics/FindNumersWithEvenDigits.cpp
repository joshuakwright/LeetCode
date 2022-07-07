class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            int eo = 0;
            while (temp > 0) {
                temp /= 10;
                eo++;
            }
            if (eo % 2 == 0) even++;
        }
        return even;
    }
};