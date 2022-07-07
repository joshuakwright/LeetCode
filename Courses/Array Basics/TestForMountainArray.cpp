class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        int mount = 1;
        if (arr.size() < 3) {return false;}
        if (arr[i] > arr[i + 1]) {return false;}
        while (arr[i] < arr[i + 1]) {
            i++;
            mount++;
            if (i + 1 == arr.size()) {return false;}
        }
        while (i + 1 < arr.size() && arr[i] > arr[i + 1]) {
            i++;
            mount++;
        }
        return mount == arr.size();
    }
};