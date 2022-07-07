//Slow
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)  {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if ((nums.at(i) + nums.at(j) == target) && (i != j)) {
                 vector<int> ans = {i, j};
                 return ans;
            }
         }    
           
    }
     return {};
    }
};

//Fast
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            
            if(prevMap.count(diff)) 
                return { prevMap[diff], i };
            prevMap[nums[i]] = i;
        }
        return {};
    }
};