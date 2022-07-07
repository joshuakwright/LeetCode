//My slower version
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int maxn = nums[0];
        int smaxn;
        int tmaxn;
        int numfound = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxn) {
                maxn = nums[i];
            }
        }
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != maxn) {
                smaxn = nums[j];
                numfound = 1;
                break;
            }
        }
        if (numfound != 1) {return maxn;}
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= smaxn && nums[i] < maxn) {
                smaxn = nums[i];
                numfound = 0;           
            }
        }
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != maxn && nums[j] != smaxn) {
                tmaxn = nums[j];
                numfound = 1;
                break;
            }
        }
        if (numfound != 1) {return maxn;}
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= tmaxn && nums[i] < smaxn) {
                tmaxn = nums[i];
            }
        }
        
        return tmaxn;
    }
};

//A faster version I found
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long m1 = LONG_MIN;
        long m2 = LONG_MIN;
        long m3 = LONG_MIN;

        
        for (auto i : nums) {
            if ((i == m1 || i ==m2 || i ==m3)) {
                continue;
            }
            if (i > m1) {
                m3 = m2;
                m2 = m1;
                m1 = i;
 
            } else if (i > m2) {
                m3 = m2;
                m2 = i;
            
            } else if (i > m3) {
                m3 = i;
            }
        }
        
        // if (m3 == INT_MIN && m2 == INT_MIN) return m1;
        if (m3 == LONG_MIN) {
            return m1;
        }
        return m3;
    } 
};