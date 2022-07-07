//My original slower version
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int k = 0;
        int i = 0;
        if (m > 0) {
        do {
                if (nums2[i] <= nums1[k]) {
                    for (int j = m - 1; j >= k; j--) {
                        nums1[j + 1] = nums1[j];
                    }
                    nums1[k] = nums2[i];
                    k++;
                    i++;
                    m++;
                }
                else {k++;}
                if (m == nums1.size()) return;
                if (k >= m) {
                    break;
                }
            } while (k < nums1.size());
        }
        
        for (; i < n; i++, k++) {
            nums1[k] = nums2[i];
        }
    }
};

//The newer faster verions someone else made
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i,j,k=n+m-1;
        i=m-1;
        j=n-1;
        while(i>=0 && j>=0){
            if(a[i] > b[j]){
                a[k]=a[i];
                i--;
                k--;
            }
            else{
                a[k]=b[j];
                j--;
                k--;
            }
        }
        while(j>=0){
            a[k]=b[j];
            j--;
            k--;
        }
    }
};