// Fastest version using twosum pointer method

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();
        
        vector<vector<int>> triplets;
        int length = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < length; i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            twoSumII(nums, i, triplets);
        }
             
        return triplets;  
    }
    
    void twoSumII(vector<int> nums, int i, vector<vector<int>> &triplets) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if(sum < 0) {
                lo++;
            }
            else if(sum > 0) {
                hi--;
            }
            else {
                triplets.push_back({nums[i], nums[lo++], nums[hi--]});
                while (lo < hi && nums[lo] == nums[lo-1]) {
                    lo++;
                } 
            }
        }
    }
};

//Faster but still slow version using a hash set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();
        
        vector<vector<int>> triplets;
        int length = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < length; i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            twoSum(nums, i, triplets);
        }
             
        return triplets;  
    }
    
    void twoSum(vector<int> nums, int i, vector<vector<int>> &triplets) {
        unordered_set<int> seen;
        for(int j = i + 1; j < nums.size(); j++) {
            int complement = -nums[i] - nums[j];
            if(seen.count(complement)) {
                triplets.push_back({nums[i], complement, nums[j]});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            seen.insert(nums[j]);
        }
    }
};

//My slow version

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();
        
        vector<vector<int>> triplets;
        int length = nums.size();
        
        set<int> iTested;
        for (int i = 0; i < length; i++) {
            if(iTested.find(nums[i]) == iTested.end()) {
                set<int> jTested;
                for (int j = i + 1; j < length; j++) {
                    if((iTested.find(nums[j]) == iTested.end()) && (jTested.find(nums[j]) == jTested.end())) {
                        set<int>kTested;
                        for (int k = j + 1; k < length; k++) {
                            if((iTested.find(nums[k]) == iTested.end()) && (jTested.find(nums[k]) == jTested.end()) && (kTested.find(nums[k]) == kTested.end())) {
                                if(((nums[i] + nums[j] + nums[k]) == 0)) {
                                    vector<int> temp{nums[i], nums[j], nums[k]};
                                    triplets.push_back(temp);
                                }
                                kTested.insert(nums[k]);
                            }   
                        }
                        jTested.insert(nums[j]);
                    }   
                }
                iTested.insert(nums[i]);
            }     
        }
        return triplets;  
    }
};