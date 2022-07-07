//second fast version but with reverse function instead of sort

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        
        int size = nums.size();
        int i;
        bool swapped = false;
        for (i = size-2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                for(int j = size-1; j > i; j--) {
                    if(nums[j] > nums[i]) {
                        swap(nums[j], nums[i]);
                        swapped = true;
                        break;
                    }
                }
            }
            if(swapped) break;
        }
        if(i == -1) {
            reverse(nums, 0);
            return;
        }
        
        reverse(nums, i + 1);
    }
    
    void reverse(vector<int> &nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
        //[7, 6, 3, 2, 1]
        //[3, 1, 5, 2, 7]
        //[3, 2, 5, 7, 1]-> [3, 1, 7, 2, 5] -> [3, 2, 1, 7, 5] -> [3, 2, 1, 5, 7]
        //[3, 4, 5, 7, 2]

//My first fast version

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        
        int size = nums.size();
        int i;
        bool swapped = false;
        for (i = size-2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                for(int j = size-1; j > i; j--) {
                    if(nums[j] > nums[i]) {
                        swap(nums[j], nums[i]);
                        swapped = true;
                        break;
                    }
                }
            }
            if(swapped) break;
        }
        if(i == -1) {
            sort(begin(nums), end(nums));
        }
        
        sort(begin(nums) + i + 1, end(nums));
    }
};
        //[7, 6, 3, 2, 1]
        //[3, 1, 5, 2, 7]
        //[3, 1, 5, 7, 2]-> [3, 1, 7, 2, 5] -> [3, 2, 1, 7, 5] -> [3, 2, 1, 5, 7]
        //[3, 4, 5, 7, 2]