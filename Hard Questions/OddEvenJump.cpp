Good Fast Version:

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int arrSize = arr.size(), goodJumps = 1;
        vector<int> higher(arrSize), lower(arrSize);
        higher[arrSize - 1] = lower[arrSize - 1] = 1;
        map<int, int> numMap;
        numMap[arr[arrSize - 1]] = arrSize - 1;
            
        for(int i = arrSize - 2; i >= 0; i--) {
            auto hi = numMap.lower_bound(arr[i]), lo = numMap.upper_bound(arr[i]);
            if (hi != numMap.end()) higher[i] = lower[hi->second];
            if (lo != numMap.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) goodJumps++;
            numMap[arr[i]] = i;
        }
        
        return goodJumps;
    }
};


First Slow Solution: Does't pass all test cases because it is too slow

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int arrLen = arr.size() - 1;
        if (arrLen == 0) return 1;
        
        int goodJumps = 1;
        
        for(int start = 0; start < arrLen; start++) {
            int jump = 1;
            for (int i = start; i <= arrLen;) {
                if (i == arrLen) {
                    goodJumps++;
                    break;
                }
                //Odd
                if(jump % 2 == 1) {
                    int minVal[2];
                    bool initialized = false;
                    for (int j = i + 1; j <= arrLen; j++) {
                        if (arr[i] <= arr[j]) {
                            if(initialized) {
                                if (arr[j] == minVal[0]) continue;
                                else {
                                    if (minVal[0] > arr[j]) {
                                        minVal[0] = arr[j];
                                        minVal[1] = j;
                                    }
                                }
                            }
                            else {
                                minVal[0] = arr[j];
                                minVal[1] = j;
                                initialized = true;
                            }
                        }
                    }
                    if (!initialized) break;
                    else {
                        i = minVal[1];
                        jump++;
                    }
                }
                //Even
                else {
                    int maxVal[2];
                    bool initialized = false;
                    for (int j = i + 1; j <= arrLen; j++) {
                        if (arr[i] >= arr[j]) {
                            if(initialized) {
                                if (arr[j] == maxVal[0]) continue;
                                else {
                                    if (maxVal[0] < arr[j]) {
                                        maxVal[0] = arr[j];
                                        maxVal[1] = j;
                                    }
                                }
                            }
                            else {
                                maxVal[0] = arr[j];
                                maxVal[1] = j;
                                initialized = true;
                            }
                        }
                    }
                    if(!initialized) break;
                    else {
                        i = maxVal[1];
                        jump++;
                    }
                }   
            }
        }
        
        return goodJumps;
    }
};

4 2 8 3 5 7 5 7 10 4 2