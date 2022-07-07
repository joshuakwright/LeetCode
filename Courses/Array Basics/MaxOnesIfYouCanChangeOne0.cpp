class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen = 0;
        int temp = 0;
        int zero = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && zero == 1) {
                maxlen = max(maxlen, temp);
                temp = 0;
                zero = 0;
                i = index;
            }
            else if (nums[i] == 0 && zero == 0) {
                zero = 1;
                temp++;
                index = i;
            }
            else {temp++;}
        }
        maxlen = max(temp, maxlen);
        return maxlen;
    }
};