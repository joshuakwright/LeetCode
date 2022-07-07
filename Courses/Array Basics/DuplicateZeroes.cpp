class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int place = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                for (int j = arr.size() - 2; j >= place; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[place] = 0;
                place += 2;
                i++;
            }
            else {place++;}
        }
    }
};