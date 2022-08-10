class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {return "";}
        if (strs.size() == 1) {return strs[0];}
        return shortestCommonPrefix(strs, 0, strs.size() - 1);
    }
    
private:
    string shortestCommonPrefix(vector<string> strs, int l, int r) {
        if (l == r) {
            return strs[l];
        }
        else {
            int mid = (l + r)/2;
            string lcpLeft = shortestCommonPrefix(strs, l , mid);
            string lcpRight = shortestCommonPrefix(strs, mid + 1,r);
            cout << lcpLeft << " " << lcpRight << "\n";
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(string sleft, string sright) {
        int min = sleft.length();
        if (sright.length() < min) {min = sright.length();}
        for (int i = 0; i < min; i++) {
            if (sleft[i] != sright[i]) {
                return sleft.erase(i);
            }
        }
        return sleft.erase(min);
    }
};

        
        