class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0;
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                maxlen = max(temp, maxlen);
                temp = 0;
            }
            else {
                temp++;
            }
        }
        maxlen = max(temp, maxlen);
        return maxlen;
    }
};