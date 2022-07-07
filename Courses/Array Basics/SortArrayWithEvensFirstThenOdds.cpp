class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = 0; i < A.size();) {
            if (A[i] % 2 != 1) {
                iter_swap(A.begin() + j, A.begin() + i);
                i++;
                j++;
            }
            else {i++;}
        }
        return A;
    }
};