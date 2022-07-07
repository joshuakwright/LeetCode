//In an array populated with numbers that are in the range of [1,n] where n is the 
size of the array, this program will figure out which numbers are missing in order for 
the array to be [1...n] with each number only showing up once
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {result.push_back(i + 1);}
        }
        return result;
    }
};