class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.size() == 1) {
            arr[0] = -1;
            return arr;
        }
        int max = arr[1];
        int l = 1;
        for (int i = 0; i < arr.size();) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] > max) {
                    max = arr[j];
                    l = j;
                }
            }
            for (; i < l; i++) {
                arr[i] = max;
            }
            max = arr[i + 1];
            l = i + 1;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};